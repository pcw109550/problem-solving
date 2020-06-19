#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int N; cin >> N; long long input[N] = {};
    for (int i = 0; i < N; i++) { cin >> input[i]; }
    long long D[N - 1][21] = {}; D[0][input[0]] = 1;
    for (int i = 1; i < N - 1; i++) {
        for (int j = 0; j < 21; j++) {
            if (!D[i - 1][j]) { continue; }
            if (0 <= j + input[i] && j + input[i] <= 20) {
                D[i][j + input[i]] += D[i - 1][j];
            }
            if (0 <= j - input[i] && j - input[i] <= 20) {
                D[i][j - input[i]] += D[i - 1][j];
            }
        }
    }
    cout << D[N - 2][input[N - 1]];
}