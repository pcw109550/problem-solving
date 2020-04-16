#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int S, K; cin >> S >> K;
    int div = S / K; long long result = 1;
    for (int i = 0; i < K; i++) {
        result *= (long long) (i < S % K ? div + 1 : div); // AM-GM
    }
    cout << result;
}