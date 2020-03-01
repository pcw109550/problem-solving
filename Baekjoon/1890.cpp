#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); int temp;
    int N; cin >> N; long long input[N][N] = {};
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> input[i][j];
        }
    }
    long long D[N][N] = {}; D[0][0] = 1;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i == N - 1 && j == N - 1) { break; }
            long long current = input[i][j];
            if (current + i < N) { D[current + i][j] = D[i][j] + D[current + i][j]; }
            if (current + j < N) { D[i][current + j] = D[i][j] + D[i][current + j]; }
        }
    }
    cout << D[N - 1][N - 1];
}