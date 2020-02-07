#include <bits/stdc++.h>
using namespace std;
int D[1000001];

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);
    int N; cin >> N;
    for (int k = 2; k <= N; k++) {
        int candidate = D[k - 1] + 1;
        if (k % 2 == 0) { candidate = min(candidate, D[k / 2] + 1); }
        if (k % 3 == 0) { candidate = min(candidate, D[k / 3] + 1); }
        D[k] = candidate;
    }
    cout << D[N];
}