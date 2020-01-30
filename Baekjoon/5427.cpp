#include <bits/stdc++.h>
using namespace std;

void debug(int *input, int N, int M) {
    cout << '\n';
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cout << *(input + M * i + j) << " ";
        }
        cout << '\n';
    }
}

#define BIGNUM 1000000

int dx[4] = {1, -1, 0,  0};
int dy[4] = {0,  0, 1, -1};

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);
    int T; cin >> T;
    for (int t = 0; t < T; t++) {
        int M, N; cin >> M >> N; int input[N][M] = {}; char temp; int input2[N][M] = {};
        pair<int, int> start; int cnt = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                cin >> temp;
                if (temp == '#') { input[i][j] =  -1; input2[i][j] =  -1; }
                if (temp == '.') { input[i][j] =   0; input2[i][j] =   0; }
                if (temp == '*') { input[i][j] =   1; input2[i][j] =   0; cnt++; }
                if (temp == '@') { input[i][j] =   0; start = {i, j}; input2[i][j] = 1; }
            }
        }
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (input[i][j] == 1) {
                    queue<pair<int, int>> Q; Q.push({i, j}); input[i][j] = 2;
                    while (!Q.empty()) {
                        pair<int, int> current = Q.front(); Q.pop();
                        for (int dir = 0; dir < 4; dir++) {
                            int X = current.first + dx[dir];
                            int Y = current.second + dy[dir];
                            if (X < 0 || Y < 0 || X >= N || Y >= M) { continue; }
                            if (input[X][Y] == -1) { continue; }
                            if (input[X][Y] == 0) {
                                input[X][Y] = input[current.first][current.second] + 1;
                                Q.push({X, Y});
                            }
                            if (input[X][Y] > input[current.first][current.second] + 1) {
                                input[X][Y] = input[current.first][current.second] + 1;
                                Q.push({X, Y});
                            }
                        }
                    }
                }
            }
        }
        queue<pair<int, int>> Q; Q.push(start);
        while (!Q.empty()) {
            pair<int, int> current = Q.front(); Q.pop();
            for (int dir = 0; dir < 4; dir++) {
                int X = current.first + dx[dir];
                int Y = current.second + dy[dir];
                if (X < 0 || Y < 0 || X >= N || Y >= M) { continue; }
                if (input2[X][Y] == -1) { continue; }
                if (input2[X][Y] == 0) {
                    input2[X][Y] = input2[current.first][current.second] + 1;
                    Q.push({X, Y});
                }
                if (input2[X][Y] > input2[current.first][current.second] + 1) {
                    input2[X][Y] = input2[current.first][current.second] + 1;
                    Q.push({X, Y});
                }
            }
        }

        // input  stores fire
        // input2 stores player
        int result[N][M] = {};
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (input[i][j] == -1) { result[i][j] = -BIGNUM; continue; }
                if (input2[i][j] == 0) { result[i][j] = -BIGNUM; input2[i][j] = -1; continue; }
                int playerstep = input2[i][j] - 1; input2[i][j] -= 1;
                int firestep;
                if (input[i][j] != 0) {
                    firestep   = input[i][j]  - 2; input[i][j]  -= 2;
                } else {
                    firestep = input[i][j] + 2 * BIGNUM + 1;
                }
                result[i][j]   = playerstep - firestep;
            }
        }
        
        //debug((int *)input,  N, M);
        //debug((int *)input2, N, M);
        //debug((int *)result, N, M);

        int min = BIGNUM;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (i == 0 || i == N - 1 || j == 0 || j == M - 1) {
                    if (result[i][j] != -BIGNUM && result[i][j] < 0) {
                        if (min > input2[i][j]) {  min = input2[i][j]; }
                    }
                }
            }
        }

        if (min == BIGNUM) { cout << "IMPOSSIBLE\n"; }
        else { cout << min + 1<< '\n';}
    }
}