#include <bits/stdc++.h>
using namespace std;

inline void task() {
    int cnt, amount; cin >> cnt;
    int coin[cnt] = {};
    for (int i = 0; i < cnt; i++) { cin >> coin[i]; }
    cin >> amount;
    int D[cnt][amount + 1] = {};
    for (int i = 0; i <= amount; i += coin[0]) {
        D[0][i] = 1;
    }
    for (int i = 1; i < cnt; i++) {
        for (int j = 0; j <= amount; j++) {
            D[i][j] = D[i - 1][j];
            if (j >= coin[i]) {
                D[i][j] += D[i][j - coin[i]];
            }
        }
    }
    cout << D[cnt - 1][amount] << '\n';
}

int main(void) {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while (T--) {
        task();
    }
}