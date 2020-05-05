#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    long long D[68] = {}; D[0] = D[1] = 1; D[2] = 2; D[3] = 4;
    for (int i = 4; i < 68; i++) {
        D[i] = D[i - 1] + D[i - 2] + D[i - 3] + D[i - 4];
    }
    int T, idx; cin >> T;
    while (T--) {
        cin >> idx;
        cout << D[idx] << '\n';
    }
}