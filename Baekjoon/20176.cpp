#include <bits/stdc++.h>
using namespace std;

using cdbl = complex<double>; 
const double PI = acos(-1);

inline unsigned bitreverse(const unsigned n, const unsigned k) {
    unsigned r, i;
    for (r = 0, i = 0; i < k; ++i)
        r |= ((n >> i) & 1) << (k - i - 1);
    return r;
}

void fft(vector<cdbl> &a, bool is_reverse=false) {
    const unsigned n = a.size(), k = __builtin_ctz(n);
    unsigned s, i, j;
    for (i = 0; i < n; i++) {
        j = bitreverse(i, k);
        if (i < j)
            swap(a[i], a[j]);
    }
    for (s = 2; s <= n; s *= 2) {
        double t = 2 * PI / s * (is_reverse? -1 : 1);
        cdbl ws(cos(t), sin(t));
        for (i = 0; i < n; i += s) {
            cdbl w(1);
            for (j = 0; j < s/2; j++) {
                cdbl tmp = a[i + j + s/2] * w;
                a[i + j + s/2] = a[i + j] - tmp;
                a[i + j] += tmp;
                w *= ws;
            }
        }
    }
    if (is_reverse)
        for (i = 0; i < n; i++)
            a[i] /= n;
}

void convolution(vector<cdbl> &a, vector<cdbl> &b) {
    const unsigned n = a.size();
    unsigned np = n, i;
 
    if (n & (n - 1)) {
        for (np = 1; np < 2 * n; np *= 2);
        a.resize(np);
        b.resize(np);
        for (i = 0; i < n; i++)
            b[np - n + i] = b[i];
    }
 
    fft(a);
    fft(b);
    for (i = 0; i < np; i++)
        a[i] *= b[i];
    fft(a, true);
 
    if (n & (n-1)) {
        a.resize(n);
        b.resize(n);
    }
}

int main(void) {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int U, M, L, temp;
    long long result = 0;
    vector<cdbl> a(1 << 17, 0), c(1 << 17, 0);
    int b[50000] = {};
    cin >> U;
    for (int i = 0; i < U; i++) {
        cin >> temp;
        a[temp + 30000] = 1;
    }
    cin >> M;
    for (int i = 0; i < M; i++) {
        cin >> temp;
        b[i] = temp + 30000;
    }
    cin >> L;
    for (int i = 0; i < L; i++) {
        cin >> temp;
        c[temp + 30000] = 1;
    }
    convolution(a, c);
    for (int i = 0; i < M; i++) {
        if (b[i] * 2 >= a.size())
            continue;
        result += static_cast<int>(round(a[b[i] * 2].real()));
    }
    cout << result;
}