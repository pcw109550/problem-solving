#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);
    int N, K; cin >> N >> K;
    int D[N + K][N + K] = {}; // {n + k - 1} \choose {n}
    D[0][0] = 1;    
    for (int i = 1; i <= N + K - 1; i++) {
        D[i][0] = D[i][i] = 1;
        for (int j = 1; j <= i - 1; j++) {
            D[i][j] = (D[i - 1][j - 1] + D[i - 1][j]) % 1000000000;
        }
    }
    cout << D[N + K - 1][N];
}