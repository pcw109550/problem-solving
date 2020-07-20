#include<bits/stdc++.h>
using namespace std;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main(void) {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int N, M;
    cin >> N >> M;
    bool Map[N][M] = {};
    char temp;
    pair<int, int> start = {-1, -1};
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> temp;
            Map[i][j] = temp == '1';
            if (Map[i][j] && start.first == -1)
                start = {i, j};
        }
    }
    bool visited[N][M] = {};
    int distance[N][M] = {};
    queue<pair<int, int> > Q;
    Q.push(start);
    visited[start.first][start.second] = true;
    while (!Q.empty()) {
        auto current = Q.front(); Q.pop();
        for (int dir = 0; dir < 4; dir++) {
            int X = current.first + dx[dir];
            int Y = current.second + dy[dir];
            if (X < 0 || Y < 0 || X >= N || Y >= M)
                continue;
            if (!visited[X][Y] && Map[X][Y]) {
                visited[X][Y] = true;
                Q.push({X, Y});
            } else {
                if (!visited[X][Y]) {
                    distance[X][Y] = distance[current.first][current.second] + 1;
                    visited[X][Y] = true;
                    Q.push({X, Y});
                } else if (visited[X][Y] && distance[current.first][current.second] + 1 < distance[X][Y]) {
                    distance[X][Y] = distance[current.first][current.second] + 1;
                    Q.push({X, Y});
                }
            }
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cout << distance[i][j] << ' ';
        }
        cout << '\n';
    }
}