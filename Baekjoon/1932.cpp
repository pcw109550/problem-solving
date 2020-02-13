#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n; int input[n][n] = {}, D[n][n] = {};
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            cin >> input[i][j];
        }
    }
    D[0][0] = input[0][0];
    for (int i = 1; i < n; i++) {
        D[i][0] = input[i][0] + D[i - 1][0];
        D[i][i] = input[i][i] + D[i - 1][i - 1];
        for (int j = 1; j <= i - 1; j++) {
            D[i][j] = input[i][j] + max(D[i - 1][j], D[i - 1][j - 1]);
        }
    }
    int result = 0;
    for (int i = 0; i < n; i++) { if ( result < D[n - 1][i]) result = D[n - 1][i]; }
    cout << result; 
}