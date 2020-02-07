#include <bits/stdc++.h>
using namespace std;
int D[1001];

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);
    int N; cin >> N;
    D[1] = 1; D[2] = 2;
    for (int k = 3; k <= N; k++) {
        D[k] = (D[k - 1] + D[k - 2]) % 10007;
    }
    cout << D[N];
}