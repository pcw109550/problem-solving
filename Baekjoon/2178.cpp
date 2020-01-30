#include <bits/stdc++.h>
using namespace std;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main(void) {
    int N, M; scanf("%d %d", &N, &M); int input[N][M];
    char column[M + 1] = {};
    for (int i = 0; i < N; i++) {
        scanf("%s", &column);
        for (int j = 0; j < M; j++) {
            input[i][j] = column[j] == '1';
        }
    }
    int cnt = 0;
    queue<pair<int, int>> Q;
    Q.push({0, 0});
    do {
        pair<int, int> current = Q.front(); Q.pop();
        for (int dir = 0; dir < 4; dir++) {
            int nx = current.first + dx[dir];
            int ny = current.second + dy[dir];
            if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
            if (input[nx][ny] == 1 && !(nx == 0 && ny == 0)) {
                Q.push({nx, ny});
                input[nx][ny] = input[current.first][current.second] + 1;
            }
        }
    } while(!Q.empty());
    printf("%d", input[N - 1][M - 1]);
}