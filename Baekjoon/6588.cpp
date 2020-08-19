#include<bits/stdc++.h>
using namespace std;
#define MAX 1000000

int main(void) {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    vector<bool> is_prime(MAX + 1, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i <= MAX; i++) {
        if (!is_prime[i])
            continue;
        for (int j = i * i; j <= MAX; j += i)
            is_prime[j] = false;
    }
    int N;
    while (true) {
        cin >> N;
        if (N == 0)
            return 0;
        for (int i = 3; i <= N / 2; i += 2) {
            if (is_prime[i] && is_prime[N - i]) {
                cout << N << " = " << i << " + " << N - i << '\n';
                break;
            }
        }
    }
}   