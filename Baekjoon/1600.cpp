#include <bits/stdc++.h>
using namespace std;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int hx[8] = {2, 2, 1, 1, -1, -1, -2, -2};
int hy[8] = {1, -1, 2, -2, 2, -2, 1, -1};

int main(void) {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int K, N, M; cin >> K >> M >> N;
    bool Map[N][M] = {};
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> Map[i][j];
        }
    }
    bool visited[N][M][K + 1] = {};
    int  distance[N][M][K + 1] = {};
    queue<tuple<int, int, int> > Q; // {x, y, k}
    for (int k = 0; k <= K; k++) {
        visited[0][0][k] = true;
        distance[0][0][k] = 1;
    }

    Q.push({0, 0, 0});
    while (!Q.empty()) {
        int currX, currY, k;
        tie(currX, currY, k) = Q.front(); Q.pop();
        for (int dir = 0; dir < 4; dir++) {
            int X = currX + dx[dir];
            int Y = currY + dy[dir];
            if (X < 0 || Y < 0 || X >= N || Y >= M) {
                continue;
            }
            if (!Map[X][Y] && !visited[X][Y][k]) {
                visited[X][Y][k] = true;
                distance[X][Y][k] = distance[currX][currY][k] + 1;
                Q.push({X, Y, k});
                continue;
            }
        }
        if (k < K) {
            for (int dir = 0; dir < 8; dir++) {
                int X = currX + hx[dir];
                int Y = currY + hy[dir];
                if (X < 0 || Y < 0 || X >= N || Y >= M) {
                    continue;
                }
                if (!Map[X][Y] && !visited[X][Y][k + 1]) {
                    visited[X][Y][k + 1] = true;
                    distance[X][Y][k + 1] = distance[currX][currY][k] + 1;
                    Q.push({X, Y, k + 1});
                    continue;
                }
            }
        }
    }
    int Min = 1 << 30;
    for (int k = 0; k <= K; k++) {
        if (visited[N - 1][M - 1][k]) {
            Min = min(Min, distance[N - 1][M - 1][k]);
        }
    }
    cout << (Min == 1 << 30 ? -1 : Min - 1);
}   