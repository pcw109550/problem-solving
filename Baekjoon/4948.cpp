#include <bits/stdc++.h>
using namespace std;
#define MAX    (123456 * 2 + 1)

int main(void) {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    vector<bool> isPrime(MAX, true);
    vector<int> primes;
    isPrime[1] = false;
    for (long long i = 2; i <= MAX; i++) {
        if (!isPrime[i]) { continue; }
        primes.push_back(i);
        for (long long j = i * i; j <= MAX; j += i) {
            isPrime[j] = false;
        }
    }
    int x;
    while (true) {
        cin >> x; if (!x) { return 0; }
        cout << upper_bound(primes.begin(), primes.end(), 2 * x) \
              - upper_bound(primes.begin(), primes.end(), x    ) << '\n';
    }
}