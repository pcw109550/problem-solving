#include <bits/stdc++.h>
using namespace std;

__int128_t power(__int128_t a, __int128_t b, __int128_t c) {
    if (c == 1) { return 0; }
    if (b == 0) { return 1; }
    __int128_t temp = power(a, b / 2, c);
    __int128_t k = temp * temp % c;
    if (b % 2 == 0) {
        return k;
    } else { 
        return k * a % c;
    }
}

__int128_t sum(__int128_t r, __int128_t n, __int128_t c) {
    if (!n)
        return 1;
    if (n == 1)
        return (r + 1) % c;
    if (n % 2)
        return sum(r, n / 2, c) * (1 + power(r, n / 2 + 1, c)) % c;
    __int128_t temp = sum(r, n / 2 - 1, c) * (1 + power(r, n / 2, c)) % c;
    temp = (temp + power(r, n, c)) % c;
    return temp;
}

int main(void) {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    long long a, r, n, mod; cin >> a >> r >> n >> mod;
    long long result = a * sum(r, n - 1, mod) % mod;
    cout << result;
}