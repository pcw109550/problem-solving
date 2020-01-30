#include <bits/stdc++.h>
using namespace std;

__int128_t power(__int128_t a, __int128_t b, __int128_t c) {
    if (c == 1) { return 0; }
    if (b == 0) { return 1; }
    long temp = power(a, b / 2, c);
    if (b % 2 == 0) {
        return temp * temp % c;
    } else {
        return temp * temp * a % c;
    }
}

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);
    long A, B, C; cin >> A >> B >> C;
    cout << (long long) (power(A, B, C) % C);
}