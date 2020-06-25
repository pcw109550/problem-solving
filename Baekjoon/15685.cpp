#include <bits/stdc++.h>
using namespace std;
bool Map[101][101];
enum Dir { D, W, A, S };
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};

int main(void) {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int N, x, y, d, g; cin >> N;
    while (N--) {
        cin >> x >> y >> d >> g;
        Map[y][x] = true;
        y = y + dy[d]; x = x + dx[d]; Map[y][x] = true;
        vector<Dir> dirs; dirs.push_back(static_cast<Dir>(d));
        for (int i = 0; i < g; i++) {
            for (int j = (1 << i) - 1; j >= 0; j--) {
                Dir dir = static_cast<Dir>((dirs[j] + 1) % 4);
                y = y + dy[dir]; x = x + dx[dir];
                Map[y][x] = true;
                dirs.push_back(dir);
            }
        }
    }
    int result = 0;
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            if (Map[i][j] && Map[i][j + 1] && Map[i + 1][j] && Map[i + 1][j + 1]) {
                result++;    
            }
        }
    }
    cout << result;
}