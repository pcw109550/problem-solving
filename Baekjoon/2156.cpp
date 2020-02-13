#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int n; cin >> n; int input[n] = {};
    for (int i = 0; i < n; i++) { cin >> input[i]; }
    if (n == 1) { cout << input[0]; return 0; }
    int D[n][3] = {};
    D[0][0] = D[0][1] = D[0][2] = input[0];
    D[1][0] = input[0] + input[1]; D[1][1] = D[1][2] = input[1];
    D[2][0] = input[2] + D[1][1];
    D[2][1] = input[2] + input[0];
    D[2][2] = input[2];
    for (int i = 3; i < n; i++) {
        D[i][0] = input[i] + max(D[i - 1][1], D[i - 1][2]);
        D[i][1] = input[i] + max(max(D[i - 2][0], D[i - 2][1]), D[i - 2][2]);
        D[i][2] = input[i] + max(max(D[i - 3][0], D[i - 3][1]), D[i - 3][2]);
    }
    cout << max(max(max(D[n - 2][0], D[n - 2][1]), D[n - 2][2]), max(max(D[n - 1][0], D[n - 1][1]), D[n - 1][2]));
}