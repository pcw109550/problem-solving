#include<bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int N, result = 0;
    cin >> N;
    vector<bool> is_prime(N + 1, true);
    is_prime[1] = false;
    for (int i = 2; i * i <= N; i++) {
        if (!is_prime[i])
            continue;
        for (int j = i * i; j <= N; j += i)
            is_prime[j] = false;
    }
    vector<int> primes;
    int cnt = 0;
    for (int i = 2; i <= N; i++)
        if (is_prime[i]) {
            primes.push_back(i);
            cnt++;
        }
    long long acc = 0;
    // Two pointers Algorithm
    int lo = 0, hi = 0;
    while (true){
        if (acc >= N)
            acc -= primes[lo++];
        else if (hi == cnt)
            break;
        else
            acc += primes[hi++];
        if (acc == N)
            result++;
    }
    cout << result;
}