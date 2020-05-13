#include <bits/stdc++.h>
using namespace std;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

// Union Find: {rank, parent}
vector<pair<int, int> > mySet(7, {0, -1});
vector<tuple<int, int, int> > edge;

int Find(int x) {
    if (mySet[x].second < 0) { return x; }
    // Path compression
    return mySet[x].second = Find(mySet[x].second);
}

bool Union(int x, int y) {
    // O(invack(N))
    int X = Find(x);
    int Y = Find(y);
    if (X == Y) { return true; }
    if (mySet[X].first < mySet[Y].first) {
        swap(X, Y);
    }
    mySet[Y].second = X;
    if (mySet[X].first == mySet[Y].first) {
        mySet[X].first++;
    }
    return false;
}

int main(void) {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int N, M; cin >> N >> M; int input[N][M] = {};
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> input[i][j];
        }
    }
    // Label islands by BFS O(N * M)
    bool visited[N][M] = {}; int cnt = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (input[i][j] && !visited[i][j]) {
                queue<pair<int, int> > Q; cnt++;
                Q.push({i, j}); visited[i][j] = true;
                while (!Q.empty()) {
                    auto current = Q.front(); Q.pop();
                    input[current.first][current.second] = cnt;
                    for (int dir = 0; dir < 4; dir++) {
                        int X = current.first + dx[dir];
                        int Y = current.second + dy[dir];
                        if (X < 0 || Y < 0 || X >= N || Y >= M) { continue; }
                        if (!visited[X][Y] && input[X][Y]) {
                            visited[X][Y] = true; Q.push({X, Y});
                        }
                    }   
                }
            }
        }
    }
    // Find horizontal edges O (N * M)
    for (int i = 0; i < N; i++) {
        int start, end; bool bridge = false, isstart = false;
        for (int j = 0; j < M; j++) {
            if (input[i][j]) { isstart = true; }
            if (!bridge && !input[i][j] && isstart) {
                bridge = true;
                start = j;
            } else if (bridge && input[i][j] && isstart) {
                bridge = false;
                end = j;
                if (end - start > 1 && input[i][start - 1] != input[i][end]) {
                    edge.push_back({end - start, input[i][start - 1], input[i][end]});
                }
            }
        }
    }
    // Find vertical edges O (N * M)
    for (int j = 0; j < M; j++) {
        int start, end; bool bridge = false, isstart = false;
        for (int i = 0; i < N; i++) {
            if (input[i][j]) { isstart = true; }
            if (!bridge && !input[i][j] && isstart) {
                bridge = true;
                start = i;
            } else if (bridge && input[i][j] && isstart) {
                bridge = false;
                end = i;
                if (end - start > 1 && input[start - 1][j] != input[end][j]) {
                    edge.push_back({end - start, input[start - 1][j], input[end][j]});
                }
            }
        }
    }
    if (!edge.size()) { cout << -1; return 0; }
    // MST: Kruskal's algorithm O (E * log(E))
    sort(edge.begin(), edge.end());
    int vnum = 0; int result = 0;
    for (int i = 0; i < edge.size(); i++) {
        int cost, v1, v2;
        tie(cost, v1, v2) = edge[i];
        if (Union(v1, v2)) { continue; }
        result += cost;
        if (++vnum == cnt - 1) { break; }
    }
    cout << (vnum == cnt - 1 ? result : -1);
}