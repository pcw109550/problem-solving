#include <bits/stdc++.h>
using namespace std;
#define INF 100000000
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

inline int dijkstra(int N) {
    int x, end, V = N * N;
    vector<pair<int, pair<int, int> > > edge[N + 1][N + 1]; // {weight, vertex}
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> x;
            for (int dir = 0; dir < 4; dir++) {
                int X = i + dx[dir];
                int Y = j + dy[dir];
                if (X < 1 || Y < 1 || X > N || Y > N) { continue; }
                edge[i][j].push_back({x, {X, Y}});
            }
            if (i == N && j == N) {
                end = x;
            }
        } 
    }
    priority_queue<pair<int, pair<int, int> >, vector<pair<int, pair<int, int> > >, greater<pair<int, pair<int, int> > > > PQ;
    int D[N + 1][N + 1]; fill(*D, *D + (N + 1) * (N + 1), INF);
    D[1][1] = 0; PQ.push({0, {1, 1}});
    while (!PQ.empty()) {
        auto current = PQ.top(); PQ.pop();
        int distance = current.first;
        auto vertex = current.second;
        if (D[vertex.first][vertex.second] == distance) {
            for (auto it : edge[vertex.first][vertex.second]) {
                int weight = it.first;
                auto nvertex = it.second;
                if (D[nvertex.first][nvertex.second] > distance + weight) {
                    D[nvertex.first][nvertex.second] = distance + weight;
                    PQ.push({D[nvertex.first][nvertex.second], {nvertex.first, nvertex.second}});
                }
            }
        }
    }
    return x + D[N][N];
}

int main(void) {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int N, cnt = 1;
    while (true) {
        cin >> N; if (!N) { return 0; }
        cout << "Problem " << cnt++ << ": " << dijkstra(N) << "\n";
    }
}
