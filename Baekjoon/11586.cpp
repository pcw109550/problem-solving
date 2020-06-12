#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int N, decision; cin >> N; char input[N][N] = {};
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> input[i][j];
        }
    }
    cin >> decision;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int I = i, J = j;
            if (decision == 2) {
                J = N - j - 1;
            } else if (decision == 3) {
                I = N - i - 1;
            }
            cout << input[I][J];
        }
        cout << '\n';
    }
}