#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int N, K, result = 0, idx; cin >> N >> K; int A[N] = {};
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    idx = N - 1;
    while (K != 0) {
        if (K >= A[idx]) {
            result += K / A[idx];
            K %= A[idx];
        }
        idx--;
    }
    cout << result;
}