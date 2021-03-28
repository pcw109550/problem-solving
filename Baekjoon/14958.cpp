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

int N, M;
string A, B;

inline vector<int> measure(char lose, char win) {
    vector<int> res (N, 0);
    vector<cdbl> a (N + M, 0);
    for (int i = 0; i < N; i++)
        if (A[i] == lose)
            a[i] = 1;
    vector<cdbl> b (N + M, 0);
    for (int i = M - 1; i >= 0; i--)
        if (B[M - 1 - i] == win)
            b[i] = 1; 
    convolution(a, b);
    for (int i = M - 1; i < N + M + 1; i++) 
        res[i - M + 1] = static_cast<int>(round(a[i].real()));
    return res;
}

int main(void) {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    // FFT: O(N * log(N))
    cin >> N >> M >> A >> B;
    auto r1 = measure('R', 'P');
    auto r2 = measure('P', 'S');
    auto r3 = measure('S', 'R');
    int result = 0;
    for (int i = 0; i < N; i++)
        result = max(result, r1[i] + r2[i] + r3[i]);
    cout << result;
}