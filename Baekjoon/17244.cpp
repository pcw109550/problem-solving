#include<bits/stdc++.h>
using namespace std;
#define INF 3000000
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int Map[50][50];
int N, M, cnt = 3;

inline void update(unordered_map<int, int> &edge, pair<int, int> point) {
    // BFS
    queue<pair<int, int> > Q;
    bool visited[N][M] = {};
    int distance[N][M] = {};
    visited[point.first][point.second] = true;
    Q.push(point);
    while (!Q.empty()) {
        auto current = Q.front(); Q.pop();
        for (int dir = 0; dir < 4; dir++) {
            int X = current.first + dx[dir];
            int Y = current.second + dy[dir];
            if (X < 0 || Y < 0 || X >= N || Y >= M || Map[X][Y] == -1)
                continue;
            if (!visited[X][Y]) {
                visited[X][Y] = true;
                distance[X][Y] = distance[current.first][current.second] + 1;
                if (Map[X][Y] >= 1)
                    edge[Map[X][Y]] = distance[X][Y];
                Q.push({X, Y});
            }
        }
    }
}

int main(void) {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cin >> M >> N;
    char temp;
    vector<pair<int, int> > point;
    pair<int, int> start, end;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++) {
            cin >> temp;
            if (temp == '#')
                Map[i][j] = -1;
            else if (temp == 'S') { 
                Map[i][j] = 1;
                start = {i, j};
            } else if (temp == 'E') {
                Map[i][j] = 2;
                end = {i, j};
            }
            else if (temp == 'X') {
                Map[i][j] = cnt++;
                point.push_back({i, j});
            }
        }
    unordered_map<int, int> edges[cnt] = {};
    update(edges[1], start);
    update(edges[2], end);
    for (int i = 3; i < cnt; i++)
        update(edges[i], point[i - 3]);
    int result = 1 << 30, temp_result, s;
    vector<int> idx;
    for (int i = 3; i < cnt; i++)
        idx.emplace_back(i);
    do {
        temp_result = 0;
        s = 1;
        for (auto it : idx) {
            temp_result += edges[s][it];
            s = it;
        }
        temp_result += edges[s][2];
        result = min(result, temp_result);
    } while (next_permutation(idx.begin(), idx.end()));
    cout << result;
}   