#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);
    int N; cin >> N; int input[N + 1] = {};
    int D[N + 1][N + 1] = {}; int d[N + 1] = {};
    for (int i = 1; i <= N; i++) { cin >> input[i]; }
    for (int i = 1; i <= N; i++) {
        for (int j = i; j >= 1; j--) {
            if (i == j) { D[i][j] = input[i]; }
            else {
                D[i][j] = d[i - j] + input[j];
            }
        }
        int d_max = 0;
        for (int j = 1; j <= i; j++) {
            if (d_max < D[i][j]) { d_max = D[i][j]; }
        }
        d[i] = d_max;
    }
    cout << d[N];
}   