#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);
    int N, result = 0; cin >> N; int input[N] = {};
    for (int i = 0; i < N; i++) { cin >> input[i]; }
    int Max = *max_element(input, input + N);
    vector<bool> isPrime(Max + 1, true);
    isPrime[1] = false;
    for (int i = 2; i * i <= Max; i++) {
        if (!isPrime[i]) { continue; }
        for (int j = i * i; j <= Max; j += i) { isPrime[j] = false; }
    }
    for (int i = 0; i < N; i++) {
        if (isPrime[input[i]]) { result++; }
    }
    cout << result;
}