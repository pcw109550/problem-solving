#include <bits/stdc++.h>
using namespace std;
#define MAX 10000

int main(void) {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    vector<bool> isPrime(MAX + 1, true);
    isPrime[1] = false;
    for (int i = 2; i * i <= MAX; i++) {
        if (!isPrime[i]) { continue; }
        for (int j = i * i; j <= MAX; j += i) {
            isPrime[j] = false;
        }
    }
    int T, x; cin >> T;
    while (T--) {
        cin >> x;
        for (int i = x / 2; i >= 2; i--) {
            if (isPrime[i] && isPrime[x - i]) {
                cout << i << ' ' << x - i << '\n';
                break;
            }
        }
    }
}