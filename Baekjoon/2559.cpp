#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int N, K; cin >> N >> K;
    int temp, Max = -(1 << 30); int acc[N + 1] = {};
    for (int i = 0; i < N; i++) { 
        cin >> temp;
        acc[i + 1] = acc[i] + temp;
        if (i >= K) {
            Max = max(Max, acc[i] - acc[i - K]);
        }
    }
    Max = max(Max, acc[N] - acc[N - K]);
    cout << Max;
}