#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int N; cin >> N; int D[N + 1] = {};
    if (N == 1) { cout << 1; return 0; }
    D[1] = 1; D[2] = 2;
    for (int i = 3; i <= N; i++) {
        D[i] = (D[i - 1] + (i % 2 ? 0 : D[i / 2])) % 1000000000; 
    }
    cout << D[N];
}