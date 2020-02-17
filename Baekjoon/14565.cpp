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

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);
    long long N, A; cin >> N >> A;
    long long addinv = N - A;
    long long mulinv = modinv(A, N);
    cout << addinv << " " << mulinv;
}