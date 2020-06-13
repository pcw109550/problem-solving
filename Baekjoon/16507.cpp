#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int R, C, Q, temp; cin >> R >> C >> Q; int D[R + 1][C + 1] = {};
    for (int i = 1; i <= R; i++) {
        for (int j = 1; j <= C; j++) {
            cin >> temp;
            D[i][j] = D[i - 1][j] + D[i][j - 1] - D[i - 1][j - 1] + temp;
        } 
    }
    int r1, c1, r2, c2, num, result;
    while (Q--) {
        cin >> r1 >> c1 >> r2 >> c2;
        num = (r2 - r1 + 1) * (c2 - c1 + 1);
        result = D[r2][c2] - D[r2][c1 - 1] - D[r1 - 1][c2] + D[r1 - 1][c1 - 1];
        cout << result / num << '\n';
    }
}