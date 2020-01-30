#include <bits/stdc++.h>
using namespace std;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);
    int T; cin >> T;
    for (int z = 0; z < T; z++) {
        int M, N, K; cin >> M >> N >> K;
        int input[N][M] = {}; int X, Y;
        for (int i = 0; i < K; i++) {
            cin >> X >> Y; input[Y][X] = 1;
        }
        int result = 0; queue<pair<int, int>> Q;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (input[i][j] == 1) { Q.push({i, j}); input[i][j] = 2; 
                    while(!Q.empty()) {
                        pair<int, int> current = Q.front(); Q.pop();
                        for (int dir = 0; dir < 4; dir++) {
                            int X = current.first + dx[dir];
                            int Y = current.second + dy[dir];
                            if (X < 0 || Y < 0 || X >= N || Y >= M) { continue; }
                            if (input[X][Y] == 1) {
                                Q.push({X, Y}); input[X][Y] = 2;
                            }
                        }
                    }
                    result++;
                }
            }
        }
        cout << result << "\n";
        result = 0;
    }
}