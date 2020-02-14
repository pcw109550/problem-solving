#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);
    int N; cin >> N;
    int D[N] = {}; D[0] = 1; D[1] = 2;
    for (int i = 2; i < N; i++) {
        D[i] = (D[i - 1] + D[i - 2]) % 15746;
    }
    cout << D[N - 1];
}