#include <bits/stdc++.h>
using namespace std;

int getmaximum(void) {
    int n, result; cin >> n; int input[n][2] = {};
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < n; j++) { 
            cin >> input[j][i];
        }
    }
    int D[n][2] = {}; D[0][0] = input[0][0]; D[0][1] = input[0][1];
    D[1][0] = input[1][0] + input[0][1];
    D[1][1] = input[1][1] + input[0][0];
    for (int i = 2; i < n; i++) {
        D[i][0] = input[i][0] + max(D[i - 1][1], D[i - 2][1]);
        D[i][1] = input[i][1] + max(D[i - 1][0], D[i - 2][0]);
    }
    result = max(D[n - 1][0], D[n - 1][1]);
    // for (int i = 0; i < n; i++) {
    //     cout << D[i][0] << " " << D[i][1] << '\n';
    // }
    return result;
}

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);
    int T; cin >> T;
    for (int i = 0; i < T; i++) { cout << getmaximum() << '\n'; }
}