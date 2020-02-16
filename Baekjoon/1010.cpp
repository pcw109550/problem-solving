#include <bits/stdc++.h>
using namespace std;
int D[30][30];

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);
    int a, b, T; cin >> T;
    D[0][0] = 1;
    for (int i = 1; i < 30; i++) {
        D[i][0] = D[i][i] = 1;
        for (int j = 1; j <= i - 1; j++) {
            D[i][j] = D[i - 1][j - 1] + D[i - 1][j];
        }
    }
    for (int i = 0; i < T; i++) {
        cin >> a >> b; cout << D[b][a] << '\n';
    }
}