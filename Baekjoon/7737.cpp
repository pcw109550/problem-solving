#include <bits/stdc++.h>
using namespace std;
#define FIELD 1'000'000'007

template<typename T>
T egcd(T a, T b, T &x, T &y) {
    T u = 1, v = 0, q, r, m, n; x = 0; y = 1;
    while (a != 0) {
        q = b / a; r = b % a;
        m = x - u * q; n = y - v * q;
        b = a; a = r; x = u; y = v; u = m; v = n; 
    }
    T gcd_result = b;
    return gcd_result;
}

template<typename T>
T modinv(T a, T n) {
    T x, y; T gcd_result = egcd(a, n, x, y);
    if (gcd_result != 1) { return -1; }
    if (x < 0) { x += n; }
    return x;
}

int main(void) {
    ios::sync_with_stdio(false); cin.tie(NULL);
    long long N, K, num = 1, denom = 1; cin >> N >> K;
    long long result = 1;
    if (K > N - K) { K = N - K; }
    for (long long i = 0; i < K; i++) {
        num = (num * (N - i)) % FIELD;
        denom = (denom * (i + 1)) % FIELD;
    }
    // O(K)
    result = (num * modinv<long long>(denom, FIELD)) % FIELD;
    cout << result;
}