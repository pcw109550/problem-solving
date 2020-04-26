#include <bits/stdc++.h>
using namespace std;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main(void) {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int R, C; cin >> R >> C;
    char temp; bool Map[R][C] = {};
    pair<int, int> start; bool startfound = false;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> temp;
            Map[i][j] = temp == '.';
        }
    }
    int barrier = 0;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (Map[i][j]) {
                int cnt = 0;
                for (int dir = 0; dir < 4; dir++) {
                    int X = i + dx[dir], Y = j + dy[dir];
                    if (X < 0 || Y < 0 || X >= R || Y >= C) { continue; }
                    if (Map[X][Y]) { cnt++; }
                }
                if (cnt < 2) { barrier++; }
            }
        }
    }
    cout << (barrier > 0);
}