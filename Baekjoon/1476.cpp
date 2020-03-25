#include <bits/stdc++.h>
using namespace std;

long long egcd(long long a, long long b, long long *x, long long *y) {
    long long u = 1, v = 0, q, r, m, n; *x = 0; *y = 1;
    while (a != 0) {
        q = b / a; r = b % a;
        m = *x - u * q; n = *y - v * q;
        b = a; a = r; *x = u; *y = v; u = m; v = n; 
    }
    long long gcd_result = b;
    return gcd_result;
}

long long modinv(long long a, long long n) {
    long long x, y; long long gcd_result = egcd(a, n, &x, &y);
    if (gcd_result != 1) { return -1; }
    if (x < 0) { x += n; }
    return x;
}

int CRT(int M, int N, int X, int Y) {
    // Chinese remainder theorem
    long long temp, x, y; if (M > N) {
        temp = M; M = N; N = temp;
        temp = X; X = Y; Y = temp;    
    }
    long long gcd = egcd(M, N, &x, &y);
    long long delta = ((X - Y) % M + M) % M;
    if (delta % gcd != 0) { return -1; }
    temp = modinv(N / gcd, M / gcd);
    if (temp == -1) { return -1; }
    // Watch out for overflow
    return (Y + N * (delta / gcd * temp)) % (M * N / gcd);
}

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);
    int E, S, M; cin >> E >> S >> M; E--; S--; M--;
    int EMax = 15, SMax = 28, MMax = 19;
    int temp = CRT(MMax, SMax, M, S);
    temp = CRT(EMax, MMax * SMax, E, temp);
    cout << temp + 1;
}
