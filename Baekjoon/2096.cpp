#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);
    int N, d1, d2, d3; cin >> N; int D1[2][3] = {}, D2[2][3];
    cin >> D1[0][0] >> D1[0][1] >> D1[0][2];
    D1[1][0] = D1[0][0]; D1[1][1] = D1[0][1]; D1[1][2] = D1[0][2];
    for (int n = 1; n < N; n++) {
        cin >> d1 >> d2 >> d3;
        D2[0][0] = d1 + min(D1[0][0], D1[0][1]);
        D2[0][1] = d2 + min(min(D1[0][0], D1[0][1]), D1[0][2]);
        D2[0][2] = d3 + min(D1[0][1], D1[0][2]);
        D2[1][0] = d1 + max(D1[1][0], D1[1][1]);
        D2[1][1] = d2 + max(max(D1[1][0], D1[1][1]), D1[1][2]);
        D2[1][2] = d3 + max(D1[1][1], D1[1][2]);
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 3; j++) {
                D1[i][j] = D2[i][j];
            }
        }
    }
    int Min = min(min(D1[0][0], D1[0][1]), D1[0][2]);
    int Max = max(max(D1[1][0], D1[1][1]), D1[1][2]);
    cout << Max << " " << Min;
}