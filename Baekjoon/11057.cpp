#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);
    int N; cin >> N; int D[N][10] = {};
    for (int i = 0; i < 10; i++) { D[0][i] = 1; }
    for (int i = 1; i < N; i++) {
        for (int j = 0; j < 10; j++) {
            for (int k = j; k < 10; k++) {
                D[i][j] = (D[i][j] + D[i - 1][k]) % 10007;
            }
        }
    }
    int result = 0;
    for (int i = 0; i < 10; i++) { result += D[N - 1][i]; } result %= 10007;
    cout << result;
}