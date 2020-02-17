#include <bits/stdc++.h>
using namespace std;

long long egcd(long long a, long long b, long long *x, long long *y) {
    long long u = 1, v = 0, q, r, m, n; *x = 0; *y = 1;
    while (a != 0) {
        q = b / a; r = b % a;
        m = *x - u * q; n = *y - v * q;
        b = a; a = r; *x = u; *y = v; u = m; v = n; 
    }
    int gcd_result = b;
    return gcd_result;
}

long long modinv(long long a, long long n) {
    long long x, y; long gcd_result = egcd(a, n, &x, &y);
    if (gcd_result != 1) { return -1; }
    if (x < 0) { x += n; }
    return x;
}

void factor(long long n, long long *p, long long *q) {
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) { *p = n / i; *q = i; return; }
    }
}

long long powmod(long long a, long long b, long long c) {
    int r = 1;
    while (b) {
        if (b % 2 == 1) { r = (r * a) % c; }
        b /= 2; a = (a * a) % c;
    }
    return r;
}

long long decrypt(long long n, long long e, long long c) {
    long long p, q; factor(n, &p, &q);
    long long d = modinv(e, (p - 1) * (q - 1));
    long long m = powmod(c, d, n);
    return m;
}

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);
    // RSA  
    int T; cin >> T; long long n, e, c, m;
    for (int t = 1; t <= T; t++) {
        cout << "Data Set " << t << ":\n";
        cin >> n >> e >> c; m = decrypt(n, e, c);
        cout << m << '\n';
        if (t != T) { cout << '\n'; }
    }
}