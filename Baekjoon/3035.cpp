#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);
    int R, C, ZR, ZC; cin >> R >> C >> ZR >> ZC;
    char input[R][C] = {};
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> input[i][j];
        }
    }
    for (int i = 0; i < R; i++) {
        for (int l = 0; l < ZR; l++) {
            for (int j = 0; j < C; j++) {
                for (int k = 0; k < ZC; k++) {
                    cout << input[i][j];
                }
            }
            cout << '\n';
        }
    }
}