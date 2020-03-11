#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);
    int N, M; cin >> N >> M; __int128_t D[N + 1][N + 1] = {};
    for (int i = 0; i <= N; i++) {
        D[i][0] = D[i][i] = 1;
        for (int j = 1; j < i; j++) {
            D[i][j] = D[i - 1][j - 1] + D[i - 1][j];
        }
    }
    __int128_t result = D[N][M];
    string s;
    do {
        int digits = result % 10;
        result /= 10;
        s.append(to_string(digits));
    } while ( result != 0 );
    for (int i = s.length() - 1; i >= 0; i--) {
        cout << s[i];
    }
}