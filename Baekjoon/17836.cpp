#include<bits/stdc++.h>
using namespace std;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main(void) {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int N, M, T;
    cin >> N >> M >> T;
    int Map[N][M] = {};
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> Map[i][j];
    bool visited[2][100][100] = {};
    int distance[2][100][100] = {};
    queue<pair<pair<int, int>, bool> > Q; // {{coord}, has_sword}
    visited[Map[0][0] == 2][0][0] = true;
    Q.push({{0, 0}, Map[0][0] == 2});
    while (!Q.empty()) {
        auto current = Q.front(); Q.pop();
        pair<int, int> coord = current.first;
        bool has_sword = current.second;
        for (int dir = 0; dir < 4; dir++) {
            int X = coord.first + dx[dir];
            int Y = coord.second + dy[dir];
            if (X < 0 || Y < 0 || X >= N || Y >= M)
                continue;
            if (has_sword) {
                if (!visited[1][X][Y]) {
                    visited[1][X][Y] = true;
                    distance[1][X][Y] = distance[1][coord.first][coord.second] + 1;
                    Q.push({{X, Y}, true});
                }
            } else {
                if (!visited[0][X][Y] && Map[X][Y] != 1) {
                    visited[0][X][Y] = true;
                    distance[0][X][Y] = distance[0][coord.first][coord.second] + 1;
                    Q.push({{X, Y}, false});
                    if (Map[X][Y] == 2) {
                        visited[1][X][Y] = true;
                        distance[1][X][Y] = distance[0][coord.first][coord.second] + 1;
                        Q.push({{X, Y}, true});
                    }
                }
            }
        }
    }
    int Min = 1 << 30;
    for (int i = 0; i < 2; i++)
        if (visited[i][N - 1][M - 1])
            Min = min(Min, distance[i][N - 1][M - 1]);
    if (Min == 1 << 30 || Min > T)
        cout << "Fail";
    else
        cout << Min;
}   