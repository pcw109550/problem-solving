#include <bits/stdc++.h>
using namespace std;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);
    int N; cin >> N; int input[N][N] = {};
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> input[i][j];
        }
    }
    queue<pair<pair<int, int>, int>> Q;
    int Map[N][N] = {}; bool done[N][N] = {}; int cnt = 0, tempcnt;
    for (int i = 0; i < N; i++) { // O(n ** 2)
        for (int j = 0; j < N; j++) {
            int recv = 0, send = 0;
            for (int dir = 0; dir < 4; dir++) {
                int X = i + dx[dir], Y = j + dy[dir];
                if (X < 0 || Y < 0 || X >= N || Y >= N) { continue; }
                if (input[X][Y] > input[i][j]) { send++; }
                if (input[X][Y] < input[i][j]) { recv++; }
            }
            if (recv == 0 && send > 0) { Q.push({{i, j}, 1}); cnt++; }
            if (recv == 0 && send == 0) { Map[i][j] = 1; done[i][j] = true; }
        }
    }
    bool isdone; int tempMax, Max = 1;
    while (!Q.empty()) { // O(n ** 2)
        tempcnt = 0;
        for (int i = 0; i < cnt; i++) {
            auto current = Q.front(); Q.pop(); Max = max(Max, current.second);
            Map[current.first.first][current.first.second] = current.second;
            done[current.first.first][current.first.second] = true;
            for (int dir = 0; dir < 4; dir++) {
                isdone = true; tempMax = 1;
                int X = current.first.first + dx[dir], Y = current.first.second + dy[dir];
                if (X < 0 || Y < 0 || X >= N || Y >= N) { continue; }
                for (int dir2 = 0; dir2 < 4; dir2++) {
                    int X2 = X + dx[dir2], Y2 = Y + dy[dir2];
                    if (X2 < 0 || Y2 < 0 || X2 >= N || Y2 >= N) { continue; }
                    if (!done[X2][Y2] && input[X][Y] > input[X2][Y2]) { isdone = false; break; }
                    if (done[X2][Y2] && input[X][Y] > input[X2][Y2]) {
                        tempMax = max(tempMax, Map[X2][Y2]);
                    }
                }
                if (isdone && !done[X][Y]) {
                    tempcnt++; Q.push({{X, Y}, tempMax + 1});
                }
            }
        }
        cnt = tempcnt;
    }
    cout << Max;
}