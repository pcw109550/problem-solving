#include <bits/stdc++.h>
using namespace std;
#define MAX 2239

int main(void) {
    ios::sync_with_stdio(false); cin.tie(NULL);
    vector<bool> isPrime(MAX + 1, true);
    vector<int> primes;
    isPrime[1] = false;
    for (int i = 2; i * i <= MAX; i++) {
        if (!isPrime[i]) {
            continue;
        }
        for (int j = i * i; j <= MAX; j += i) {
            isPrime[j] = false;
        }
    }
    for (int i = 2; i <= MAX; i++) {
        if (isPrime[i]) {
            primes.push_back(i);
        }
    }
    int T, N; cin >> T; int input[T] = {};
    for (int i = 0; i < T; i++) { cin >> input[i]; }
    for (int i = 0; i < T; i++) {
        N = input[i];
        auto it = primes.begin();
        while (N > 1) {
            if (!(N % *it)) {
                cout << *it << ' ';
                N /= *it;
                continue;
            }
            it++;
            if (*it * *it > N) {
                cout << N << ' ';
                break;
            } 
        }
        cout << '\n';
    }
}