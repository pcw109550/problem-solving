#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n = 1000000;
    vector<bool> isPrime(n + 1, true);
    isPrime[1] = false;
    for (long long i = 2; i * i <= n; i++) {
        if (!isPrime[i]) { continue; }
        for (long long j = i * i; j <= n; j += i) { isPrime[j] = false; }
    }
    int T; long long input; bool bad; cin >> T;
    while (T--) {
        cin >> input; bad = false;
        for (int i = 2; i <= n; i++) {
            if (isPrime[i] && input % i == 0) { bad = true; break; }
        }
        cout << (bad ? "NO" : "YES") << '\n';
    }
}