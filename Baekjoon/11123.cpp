#include<bits/stdc++.h>
using namespace std;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void task(void) {
    int N, M, result = 0;
    char temp;
    cin >> N >> M;
    bool Map[N][M] = {};
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++) {
            cin >> temp;
            Map[i][j] = temp == '#';
        }
    bool visited[N][M] = {};
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (visited[i][j])
                continue;
            if (Map[i][j]) {
                queue<pair<int, int> > Q;
                Q.push({i, j});
                visited[i][j] = true;
                while (!Q.empty()) {
                    auto current = Q.front(); Q.pop();
                    for (int dir = 0; dir < 4; dir++) {
                        int X = current.first + dx[dir];
                        int Y = current.second + dy[dir];
                        if (X < 0 || Y < 0 || X >= N || Y >= M)
                            continue;
                        if (!visited[X][Y] && Map[current.first][current.second]) {
                            visited[X][Y] = true;
                            Q.push({X, Y});
                        }
                    }
                }
                result++;
            }
        }
    }
    cout << result << '\n';
}

int main(void) {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--)
        task();
}