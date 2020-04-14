#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int M, N; cin >> M >> N;
    vector<bool> isPrime (N + 1, true); isPrime[1] = false;
    for (int i = 2; i * i <= N; i++) {
        if (!isPrime[i]) { continue; }
        for (int j = i * i ; j <= N; j += i) {
            isPrime[j] = false;
        }
    }
    int Min = -1, sum = 0;
    for (int i = M; i <= N; i++) {
        if (isPrime[i]) {
            if (Min == -1) { Min = i; }
            sum += i;
        }
    }
    if (Min == -1) { cout << -1; }
    else { cout << sum << '\n' << Min; }
}