#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    long long N, K, temp; cin >> N >> K;
    vector<long long> D(N + 1); D[0] = 0;
    for (int i = 1; i <= N; i++) { 
        cin >> temp;
        D[i] = D[i - 1] + temp;
    }
    for (int m = N / 3; m >= 0; m--) {
        for (int i = 0; i <= N - 3 * m; i++) {
            if (D[i + m] - D[i] > K)
                continue;
            if (D[i + 2 * m] - D[i + m] > K)
                continue;
            if (D[i + 3 * m] - D[i + 2 * m] > K)
                continue;
            cout << m;
            return 0;
        }
    }
    cout << 0;
}