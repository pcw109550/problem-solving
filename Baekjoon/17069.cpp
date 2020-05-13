#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int N; cin >> N; int Map[N + 1][N + 1] = {}; // DP
    long long D1[N + 1][N + 1] = {}, D2[N + 1][N + 1] = {}, D3[N + 1][N + 1] = {};
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> Map[i][j];
        }
    }
    D1[1][2] = 1;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (!Map[i][j]) {
                D1[i][j] += D1[i][j - 1] + D3[i][j - 1];
                D2[i][j] += D2[i - 1][j] + D3[i - 1][j];
                if (!Map[i - 1][j] && !Map[i][j - 1]) {
                    D3[i][j] += D1[i - 1][j - 1] + D2[i - 1][j - 1] + D3[i - 1][j - 1];
                }
            }
        }
    }
    cout << D1[N][N] + D2[N][N] + D3[N][N];
}