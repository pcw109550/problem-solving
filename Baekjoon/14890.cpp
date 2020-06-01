#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);
    int N, L; cin >> N >> L; int input[N][N] = {};
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> input[i][j];
        }
    }
    int result = 0;
    for (int i = 0; i < N; i++) {
        int base = input[i][0], cnt = 0, idx; bool flag = true;
        for (int j = 1; j < N; j++) {
            if (base == input[i][j]) { continue; }
            if (abs(base - input[i][j]) >= 2) { flag = false; break; }
            if (base == input[i][j] - 1) {
                for (int k = j - 1; k > j - 1 - L; k--) {
                    if (k < 0 || input[i][k] != base) { flag = false; break; }
                }
                for (int k = j - 1 - L; k > j - 1 - 2 * L; k--) {
                    if (k < 0) { continue; }
                    if (input[i][k] == input[i][j]) { flag = false; break; }
                }
                base = input[i][j];
            }
            if (base == input[i][j] + 1) {
                for (int k = j; k < j + L; k++) {
                    if (k >= N || input[i][k] != input[i][j]) { flag = false; break; }  
                }
                base = input[i][j];
            }

        }
        if (flag) { result++; }
    }
    for (int i = 0; i < N; i++) {
        int base = input[0][i], cnt = 0, idx; bool flag = true;
        for (int j = 1; j < N; j++) {
            if (base == input[j][i]) { continue; }
            if (abs(base - input[j][i]) >= 2) { flag = false; break; }
            if (base == input[j][i] - 1) {
                for (int k = j - 1; k > j - 1 - L; k--) {
                    if (k < 0 || input[k][i] != base) { flag = false; break; }
                }
                for (int k = j - 1 - L; k > j - 1 - 2 * L; k--) {
                    if (k < 0) { continue; }
                    if (input[k][i] == input[j][i]) { flag = false; break; }
                }
                base = input[j][i];
            }
            if (base == input[j][i] + 1) {
                for (int k = j; k < j + L; k++) {
                    if (k >= N || input[k][i] != input[j][i]) { flag = false; break; }  
                }
                base = input[j][i];
            }

        }
        if (flag) { result++; }
    }
    cout << result;
}