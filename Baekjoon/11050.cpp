#include <bits/stdc++.h>
using namespace std;
int D[1001][1001];

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);
    int N, K; cin >> N >> K;
    D[1][0] = D[1][1] = 1;
    for (int n = 2; n <= N; n++) {
        D[n][0] = D[n][n] = 1;
        for (int k = 1; k <= n - 1; k++) {
            D[n][k] = (D[n - 1][k - 1] + D[n - 1][k]);
        }
    }
    cout << D[N][K];
}