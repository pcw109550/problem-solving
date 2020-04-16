#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int N; cin >> N; int A[3] = {300, 60, 10}, B[3] = {};
    for (int i = 0; i < 3; i++) {
        B[i] = N / A[i]; N %= A[i];
    }
    if (N == 0) {
        cout << B[0] << ' ' << B[1] << ' ' << B[2];
    } else {
        cout << -1;
    }
}