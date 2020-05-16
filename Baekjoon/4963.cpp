#include <bits/stdc++.h>
using namespace std;
int dx[8] = {1, 1, 1, -1, -1, -1, 0, 0};
int dy[8] = {1, 0, -1, 1, 0, -1, 1, -1};

inline void task(int N, int M) {
    bool Map[N][M] = {};
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> Map[i][j];
        }
    }
    bool visited[N][M] = {};
    int cnt = 0;
    // BFS O(N * M)
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (Map[i][j] && !visited[i][j]) {
                cnt++;
                visited[i][j] = true;
                queue<pair<int, int> > Q; Q.push({i, j});
                while (!Q.empty()) {
                    auto current = Q.front(); Q.pop();
                    for (int dir = 0; dir < 8; dir++) {
                        int X = current.first + dx[dir], Y = current.second + dy[dir];
                        if (X < 0 || Y < 0 || X >= N || Y >= M) { continue; }
                        if (Map[X][Y] && !visited[X][Y]) {
                            visited[X][Y] = true;
                            Q.push({X, Y});
                        }
                    }
                }
            }
        }
    }
    cout << cnt << '\n';
}

int main(void) {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int N, M;
    while (true) {
        cin >> M >> N;
        if (N == 0 && M == 0) { return 0; }
        task(N, M);
    }
}