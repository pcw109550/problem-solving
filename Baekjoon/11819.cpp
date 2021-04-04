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

int main(void) {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    long long A, B, C; cin >> A >> B >> C;
    cout << static_cast<long long>(power(A, B, C) % C);
}