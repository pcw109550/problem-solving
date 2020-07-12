#include<bits/stdc++.h>
using namespace std;
int dx[6] = {-2, -2, 0, 0, 2, 2 };
int dy[6] = {-1, 1, -2, 2, -1, 1};

int main(void) {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int N, r1, c1, r2, c2;
    cin >> N >> r1 >> c1 >> r2 >> c2;
    int Map[N][N] = {};
    bool visited[N][N] = {};
    queue<pair<int, int> > Q;
    Q.push({r1, c1}); visited[r1][c1] = true;
    while (!Q.empty()) {
        auto current = Q.front(); Q.pop();
        for (int dir = 0; dir < 6; dir++) {
            int X = current.first + dx[dir];
            int Y = current.second + dy[dir];
            if (X < 0 || Y < 0 || X >= N || Y >= N) { continue; }
            if (!visited[X][Y]) {
                visited[X][Y] = true;
                Map[X][Y] = Map[current.first][current.second] + 1;
                Q.push({X, Y});
            }
        }
    }
    cout << (visited[r2][c2] ? Map[r2][c2] : -1);
}