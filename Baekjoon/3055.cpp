#include <bits/stdc++.h>
using namespace std;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);
    pair<int, int> start, hole;
    int N, M; cin >> N >> M; char input[N][M] = {};
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> input[i][j];
            if (input[i][j] == 'S') { start = {i, j}; }
            if (input[i][j] == 'D') { hole = {i, j}; }
        }
    }
    int flood[N][M] = {}; bool visited[N][M] = {}; queue<pair<int, int>> Q;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (!visited[i][j] && input[i][j] == '*') {
                visited[i][j] = true; Q.push({i, j});
                while (!Q.empty()) {
                    auto current = Q.front(); Q.pop();
                    for (int dir = 0; dir < 4; dir++) {
                        int X = current.first + dx[dir], Y = current.second + dy[dir];
                        if (X < 0 || Y < 0 || X >= N || Y >= M) { continue; }
                        if (!visited[X][Y] && (input[X][Y] == '.' || input[X][Y] == 'S')) {
                            visited[X][Y] = true; Q.push({X, Y});
                            flood[X][Y] = flood[current.first][current.second] + 1; continue;
                        }
                        if (visited[X][Y] && (input[X][Y] == '.' || input[X][Y] == 'S')) {
                            if (flood[X][Y] > flood[current.first][current.second] + 1) {
                                flood[X][Y] = flood[current.first][current.second] + 1;
                                Q.push({X, Y}); continue;
                            }
                        }
                    }
                }
            }
        }
    }
    int path[N][M] = {}; bool visited2[N][M] = {};
    Q.push(start); visited2[start.first][start.second] = true;
    while (!Q.empty()) {
        auto current = Q.front(); Q.pop();
        for (int dir = 0; dir < 4; dir++) {
            int X = current.first + dx[dir], Y = current.second + dy[dir];
            if (X < 0 || Y < 0 || X >= N || Y >= M) { continue; }
            if (!visited2[X][Y] && (input[X][Y] == '.' || input[X][Y] == 'D')) {
                if (input[X][Y] == 'D' || !visited[X][Y] || (visited[X][Y] && flood[X][Y] > path[current.first][current.second] + 1)) {
                    visited2[X][Y] = true; Q.push({X, Y});
                    path[X][Y] = path[current.first][current.second] + 1; continue;
                }
            }
            if (visited2[X][Y] && (input[X][Y] == '.' || input[X][Y] == 'D')) {
                if (input[X][Y] == 'D' || !visited[X][Y] || (visited[X][Y] && flood[X][Y] > path[current.first][current.second] + 1)) {
                    if (path[X][Y] > path[current.first][current.second] + 1) {
                        Q.push({X, Y}); path[X][Y] = path[current.first][current.second] + 1; continue;
                    }
                }
            }
        }
    }
    if (path[hole.first][hole.second] == 0) {
        cout << "KAKTUS";
    } else {
        cout << path[hole.first][hole.second];
    }
}