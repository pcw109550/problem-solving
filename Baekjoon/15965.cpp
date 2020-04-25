#include <bits/stdc++.h>
using namespace std;
#define MAX 7368787

int main(void) {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int K; cin >> K;
    vector<bool> isPrime(MAX + 1, true);
    isPrime[1] = true;
    int cnt = 0;
    for (int i = 2; i * i <= MAX; i++) {
        if (!isPrime[i]) { continue; }
        for (int j = i * i; j <= MAX; j += i) {
            isPrime[j] = false;
        }
    }
    for (int i = 2; i <= MAX; i++) {
        if (isPrime[i]) { cnt++; }
        if (cnt == K) { 
            cout << i;
            return 0;
        }
    }
}