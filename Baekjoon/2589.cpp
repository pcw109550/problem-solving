#include <bits/stdc++.h>
using namespace std;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main(void) {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int N, M; char temp; cin >> N >> M; bool Map[N][M] = {};
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> temp; Map[i][j] = temp == 'L'; 
        }
    }
    int result = -1;
    for (int i = 0; i < N; i++) { // O(N ** 2 * M ** 2)
        for (int j = 0; j < M; j++) {
            if (Map[i][j]) {
                queue<pair<int, int>> Q; int visited[N][M] = {};
                int Max = 1; visited[i][j] = 1; Q.push({i, j});
                while (!Q.empty()) {
                    auto current = Q.front(); Q.pop();
                    for (int dir = 0; dir < 4; dir++) {
                        int X = current.first + dx[dir], Y = current.second + dy[dir];
                        if (X < 0 || Y < 0 || X >= N || Y >= M) { continue; }
                        if (!visited[X][Y] && Map[X][Y]) {
                            visited[X][Y] = visited[current.first][current.second] + 1;
                            Max = max(Max, visited[X][Y]);
                            Q.push({X, Y}); continue;
                        }
                    }
                }
                result = max(result, Max - 1);
            }
        }
    }
    cout << result;
}