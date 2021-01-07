#include <bits/stdc++.h>
using namespace std;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main(void) {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    // O(N ** max(R, C))
    int R, C, result = 0;
    char temp;
    cin >> R >> C;
    int Map[R][C];
    for (int i = 0; i < R; i++)
        for (int j = 0; j < C; j++) {
            cin >> temp;
            Map[i][j] = temp - 'A';
        }
    stack<pair<pair<int, int>, int> > S; // {{X, Y}, encode}
    S.push({{0, 0}, 1 << Map[0][0]});
    while (!S.empty()) {
        auto current = S.top(); S.pop();
        auto coord = current.first;
        int encode = current.second;
        int num = __builtin_popcount(encode);
        result = max(result, num);
        for (int dir = 0; dir < 4; dir++) {
            int X = coord.first + dx[dir];
            int Y = coord.second + dy[dir];
            if (X < 0 || Y < 0 || X >= R || Y >= C)
                continue;
            if ((encode >> Map[X][Y]) & 1)
                continue;
            if (num + 1 >= 26) {
                cout << 26;
                return 0;
            }
            S.push({{X, Y}, encode | (1 << Map[X][Y])});
        }
    }
    cout << result;
    return 0;
}