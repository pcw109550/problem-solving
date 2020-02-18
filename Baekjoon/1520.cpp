#include <bits/stdc++.h>
using namespace std;
int input[500][500], D[500][500]; int M, N;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> M >> N;
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            cin >> input[i][j];
        }
    }
    bool cand[M][N] = {};
    queue<pair<int, int>> Q; Q.push({0, 0}); cand[0][0] = true;
    // Some weird BFS solution? How to DP?
    while (!Q.empty()) {
        auto current = Q.front(); Q.pop();
        for (int dir = 0; dir < 4; dir++) {
            int X = current.first + dx[dir], Y = current.second + dy[dir];
            if (X < 0 || Y < 0 || X >= M || Y >= N) { continue; }
            if (!cand[X][Y] && input[X][Y] < input[current.first][current.second]) {
                cand[X][Y] = true; Q.push({X, Y});
            }
        }
    }
    bool visited[M][N] = {};
    Q.push({0, 0}); D[0][0] = 1; visited[0][0] = true;
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            if (!Q.empty()) {
                auto current = Q.front(); Q.pop();
                for (int dir = 0; dir < 4; dir++) {
                    int X = current.first + dx[dir], Y = current.second + dy[dir];
                    if (X < 0 || Y < 0 || X >= M || Y >= N) { continue; }
                    if (!visited[X][Y] && input[current.first][current.second] > input[X][Y]) {
                        int cnt = 0, cnt2 = 0, sum = 0;
                        for (int dir2 = 0; dir2 < 4; dir2++) {
                            int x = X + dx[dir2], y = Y + dy[dir2];
                            if (x < 0 || y < 0 || x >= M || y >= N) { continue; }
                            if (visited[x][y] && input[X][Y] < input[x][y]) { cnt++; sum += D[x][y]; }
                            if (input[X][Y] < input[x][y] && cand[x][y]) { cnt2++; }
                        }
                        if (cnt == cnt2) {
                            D[X][Y] = sum; visited[X][Y] = true; Q.push({X, Y}); continue;
                        }
                    }
                }
            }
        }
    }
    cout << D[M - 1][N - 1];
}