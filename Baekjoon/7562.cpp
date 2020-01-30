#include <bits/stdc++.h>
using namespace std;

int dx[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
int dy[8] = {-1,  1,  2, -2, 2,-2, 1,-1};

void debug(int *input, int N) {
    cout << "\n";
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << *(input + N * i + j) << " ";
        }
        cout << "\n";
    }
}

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);
    int T; cin >> T;
    int curX, curY, desX, desY, N;
    for (int t = 0; t < T; t++) {
        cin >> N >> curX >> curY >> desX >> desY;
        if (curX == desX && curY == desY) { cout << 0 << '\n'; continue; }
        queue<pair<int, int>> Q; bool visited[N][N] = {}; int input[N][N] = {};
        input[curX][curY] = 1;
        Q.push({curX, curY}); visited[curX][curY] = true;
        while (!Q.empty()) {
            pair<int, int> current = Q.front(); Q.pop();
            for (int dir = 0; dir < 8; dir++) {
                int X = current.first + dx[dir];
                int Y = current.second + dy[dir];
                if (X < 0 || Y < 0 || X >= N || Y >= N) { continue; }
                if (!visited[X][Y]) {
                    visited[X][Y] = true; Q.push({X, Y});
                    input[X][Y] = input[current.first][current.second] + 1;
                }
            }
        }
        cout << input[desX][desY] - 1 << '\n';
    }
}