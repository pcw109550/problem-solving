#include <bits/stdc++.h>
using namespace std;
int N, M; int input[1001][1001];
#define DP

#ifdef BFS
int dx[3] = {0, 1, 1};
int dy[3] = {1, 0, 1};
#endif

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> input[i][j];
        }
    }
#ifdef DP
    int D[N][M] = {};
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            D[i][j] = input[i][j]; int add = 0;
            if (i >= 1) { add = max(add, D[i - 1][j]); }
            if (j >= 1) { add = max(add, D[i][j - 1]); }
            if (i >= 1 && j >= 1) { add = max(add, D[i - 1][j - 1]); }
            D[i][j] += add;
        }
    }
    cout << D[N - 1][M - 1];
#endif

#ifdef BFS
    bool visited[N][M] = {}; int D[N][M] = {};
    D[0][0] = input[0][0];
    queue<pair<int, int>> Q; Q.push({0, 0}); visited[0][0] = true;
    while (!Q.empty()) {
        auto current = Q.front(); Q.pop();
        for (int dir = 0; dir < 3; dir++) {
            int X = current.first + dx[dir], Y = current.second + dy[dir];
            if (X < 0 || Y < 0 || X >= N || Y >= M) { continue; }
            if (!visited[X][Y]) {
                D[X][Y] = D[current.first][current.second] + input[X][Y];
                visited[X][Y] = true; Q.push({X, Y}); continue;
            }
            if (D[X][Y] < D[current.first][current.second] + input[X][Y]) {
                D[X][Y] = D[current.first][current.second] + input[X][Y];
                Q.push({X, Y}); continue;
            }
        }
    }
    cout << D[N - 1][M - 1];
#endif
}