#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);
    int M, N; cin >> M >> N;
    vector<bool> isPrime(N + 1, true);
    isPrime[1] = false;
    for (int i = 2; i * i <= N; i++) {
        if (!isPrime[i]) { continue; }
        for (int j = i * i; j <= N; j += i) { isPrime[j] = false; }
    }
    for (int i = M; i <= N; i++) {
        if (isPrime[i]) { cout << i << '\n'; }
    }
}