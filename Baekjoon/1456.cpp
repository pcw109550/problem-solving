#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);
    long long M, N, result = 0; cin >> M >> N;
    long long n = sqrt(N) + 1; 
    vector<bool> isPrime(n + 1, true);
    isPrime[1] = false;
    for (long long i = 2; i * i <= n; i++) {
        if (!isPrime[i]) { continue; }
        for (long long j = i * i; j <= n; j += i) { isPrime[j] = false; }
    }
    for (long long i = 2; i <= n; i++) {
        if (isPrime[i]) {
            __int128_t start = i * i; // used __int128_t to avoid overflow
            while (start <= (__int128_t)N) {
                if ((__int128_t)M <= start) { result++; }
                start *= i;
                // to improve: binary search
            }
        }
    }
    cout << result;
}