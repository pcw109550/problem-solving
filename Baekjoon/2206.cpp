#include <bits/stdc++.h>
using namespace std;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main(void) {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int N, M; cin >> N >> M; char temp; bool Map[N][M] = {};
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> temp;
            Map[i][j] = temp == '1';
        }
    }
    queue<tuple<int, int, bool> > Q; // {x, y, isbroken}
    bool visited[N][M][2] = {};
    int  dist[N][M][2] = {};
    Q.push({0, 0, false});
    dist[0][0][0] = dist[0][0][1] = 1;
    visited[0][0][0] = visited[0][0][1] = true;
    while (!Q.empty()) {
        int currX, currY; bool currBroken;
        tie(currX, currY, currBroken) = Q.front(); Q.pop();
        for (int dir = 0; dir < 4; dir++) {
            int X = currX + dx[dir];
            int Y = currY + dy[dir];
            if (X < 0 || Y < 0 || X >= N || Y >= M) {
                continue;
            }
            if (!currBroken) {
                if (!Map[X][Y] && !visited[X][Y][0]) {
                    visited[X][Y][0] = true;
                    dist[X][Y][0] = dist[currX][currY][0] + 1;
                    Q.push({X, Y, false});
                } else if (Map[X][Y] && !visited[X][Y][1]) {
                    visited[X][Y][1] = true;
                    dist[X][Y][1] = dist[currX][currY][0] + 1;
                    Q.push({X, Y, true});
                }
            } else {
                if (!Map[X][Y] && !visited[X][Y][1]) {
                    visited[X][Y][1] = true;
                    dist[X][Y][1] = dist[currX][currY][1] + 1;
                    Q.push({X, Y, true});
                }
            }
        }
    }
    if (visited[N - 1][M - 1][0]) {
        if (visited[N - 1][M - 1][1]) {
            cout << min(dist[N - 1][M - 1][0], dist[N - 1][M - 1][1]);
        } else {
            cout << dist[N - 1][M - 1][0];
        }
    } else {
        if (visited[N - 1][M - 1][1]) {
            cout << dist[N - 1][M - 1][1];
        }
        else {
            cout << -1;
        }
    }
}