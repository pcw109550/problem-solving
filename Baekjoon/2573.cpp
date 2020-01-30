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
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);
    int N, M; cin >> N >> M; int input[N][M] = {};
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> input[i][j]; 
        }
    }
    queue<pair<int, int>> Q;
    int cnt = 0, trial = 0; 
    while (true) {
        trial++;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (input[i][j] != 0) {
                    bool updated[N][M] = {};
                    Q.push({i, j}); updated[i][j] = true;
                    while (!Q.empty()) {
                        pair<int, int> current = Q.front(); Q.pop();
                        for (int dir = 0; dir < 4; dir++) {
                            int X = current.first + dx[dir];
                            int Y = current.second + dy[dir];
                            if (X < 0 || Y < 0 || X >= N || Y >= M) { continue; }
                            if (!updated[X][Y] && input[X][Y] == 0) {
                                if (input[current.first][current.second] > 0) {
                                    input[current.first][current.second]--;
                                }
                            }
                            if (!updated[X][Y] && input[X][Y] > 0) {
                                Q.push({X, Y}); updated[X][Y] = true;
                            }
                        }
                    }
                    goto end;
                }
            }
        }
end:
        bool visited[N][M] = {};
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (!visited[i][j] && input[i][j] != 0) {
                    cnt++;
                    Q.push({i, j}); visited[i][j] = true;
                    while (!Q.empty()) {
                        pair<int, int> current = Q.front(); Q.pop();
                        for (int dir = 0; dir < 4; dir++) {
                            int X = current.first + dx[dir];
                            int Y = current.second + dy[dir];
                            if (X < 0 || Y < 0 || X >= N || Y >= M) { continue; }
                            if (!visited[X][Y] && input[X][Y] > 0) {
                                Q.push({X, Y}); visited[X][Y] = true;
                            }
                        }
                    }
                }
            }
        }
        if (cnt > 1) {cout << trial; return 0; }
        if (cnt == 0) {cout << 0; return 0; }
        cnt = 0;
    }
    //debug((int *)input, N, M);
}