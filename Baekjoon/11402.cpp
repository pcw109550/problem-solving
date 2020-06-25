#include <bits/stdc++.h>
using namespace std;

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

template<typename T>
T nchoosek(T N, T K, T M) {
    T num = 1, denom = 1, result = 1;
    if (N < K) { return 0; }
    if (K > N - K) { K = N - K; }
    for (T i = 0; i < K; i++) {
        num = (num * (N - i)) % M;
        denom = (denom * (i + 1)) % M;
    }
    result = (num * modinv<T>(denom, M)) % M;
    return result;
}

int main(void) {
    ios::sync_with_stdio(false); cin.tie(NULL);
    // Lucas' theorem
    // O(M)
    long long N, K, M; cin >> N >> K >> M;
    long long result = 1;
    long long n = N, k = K;
    while (n > 0 || k > 0) {
        result = (result * nchoosek<long long>(n % M, k % M, M)) % M;
        n /= M; k /= M;
    }
    cout << result;
}