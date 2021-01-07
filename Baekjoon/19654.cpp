#include <bits/stdc++.h>
using namespace std;
int dx[9] = {1, 1, 1, 0, 0, 0, -1, -1, -1};
int dy[9] = {1, 0, -1, 1, 0, -1, 1, 0, -1};

int main(void) {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    char temp;
    int Map[8][8] = {};
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            cin >> temp;
            Map[i][j] = temp == '#';
        }
    }
    queue<pair<pair<int, int>, int> > Q; // {{x, y}, step}
    Q.push({{7, 0}, 0});
    while (!Q.empty()) {
        auto current = Q.front(); Q.pop();
        auto coord = current.first;
        int step = current.second;
        for (int dir = 0; dir < 9; dir++) {
            int X = coord.first + dx[dir];
            int Y = coord.second + dy[dir];
            if (X < 0 || Y < 0 || X >= 8 || Y >= 8)
                continue;
            if (X - step >= 0 && Map[X - step][Y])
                continue;
            if (X - step - 1 >= 0 && Map[X - step - 1][Y])
                continue;
            if (step + 1 > 7 || (X == 0 && Y == 7)) {
                cout << 1;
                return 0;
            }
            Q.push({{X, Y}, step + 1});
        }
    }
    cout << 0;
    return 0;
}   