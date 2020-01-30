#include <bits/stdc++.h>
using namespace std;

void debug(int *input, int H, int N, int M) {
    cout << "\n";
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < M; k++) {
                cout << *(input + k + M * j + M * N * i) << " ";
            }
            cout << "\n";
        }
    }
}

int dx[6] = {1, -1, 0,  0, 0,  0}; 
int dy[6] = {0,  0, 1, -1, 0,  0};
int dz[6] = {0,  0, 0,  0, 1, -1};

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);
    int M, N, H; cin >> M >> N >> H; int input[H][N][M] = {};
    int riped = 0, notriped = 0, none = 0;
    queue<pair<int, pair<int, int>>> Q;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < M; k++) {
                cin >> input[i][j][k];
                if (input[i][j][k] == -1) { none++; }
                if (input[i][j][k] ==  0) { notriped++; }
                if (input[i][j][k] ==  1) { riped++;
                    Q.push({i, {j, k}});
                }
            }
        }
    }
    if (riped + none == H * N * M) { cout << 0; return 0; }
    while (!Q.empty()) {
        pair<int, pair<int, int>> current = Q.front(); Q.pop();
        int X = current.first; int Y = current.second.first; int Z = current.second.second;
        for (int dir = 0; dir < 6; dir++) {
            int x = X + dx[dir]; int y = Y + dy[dir]; int z = Z + dz[dir];
            if (0 > x || 0 > y || 0 > z || x >= H || y >= N || z >= M) { continue; }
            if (input[x][y][z] == -1) { continue; }
            if (input[x][y][z] == 0) {
                input[x][y][z] = input[X][Y][Z] + 1; Q.push({x, {y, z}});
            }
            if (input[x][y][z] > input[X][Y][Z] + 1) {
                input[x][y][z] = input[X][Y][Z] + 1; Q.push({x, {y, z}});
            }
        }
    }
    int result = 0;
     for (int i = 0; i < H; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < M; k++) {
                if (input[i][j][k] == 0) { cout << -1; return 0; }
                if (input[i][j][k] > result) { result = input[i][j][k]; }
            }
        }
    }
    cout << result - 1;
    //debug((int *)input, H, N, M);
}