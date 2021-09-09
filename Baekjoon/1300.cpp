#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    // O(N * log(N))
    long long N, K; cin >> N >> K;
    long long lo = 1, hi = N * N;
    long long result = 1;
    while (lo <= hi) {
        long long mid = (lo + hi) / 2;
        long long sum = 0;
        for (long long i = 1; i <= N; i++)
            sum += min(N, mid / i);
        if (sum >= K) {
            result = mid;
            hi = mid - 1;
        } else 
            lo = mid + 1;
    }
    cout << result << endl;
} 