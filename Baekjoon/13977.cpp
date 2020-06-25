#include <bits/stdc++.h>
using namespace std;
#define FIELD 1'000'000'007
int acc[4000001];

template<typename T>
T powmod(T a, T b, T c) {
    T r = 1;
    while (b) {
        if (b % 2 == 1) { r = (r * a) % c; }
        b /= 2; a = (a * a) % c;
    }
    return r;
}
template<typename T>
inline void nchoosek() {
    T N, K; cin >> N >> K;
    T numerator = (acc[N] * powmod<T>(acc[N - K], FIELD - 2, FIELD)) % FIELD;
    T denominator = acc[K];
    T result = (numerator * powmod<T>(denominator, FIELD - 2, FIELD)) % FIELD;
    cout << result << '\n';
}

int main(void) {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int M; long long N, K, n = 1, d = 1; cin >> M;
    acc[0] = 1;
    for (long long i = 1; i <= 4000000; i++) {
        acc[i] = (acc[i - 1] * i) % FIELD;
    }
    while (M--) { nchoosek<long long>(); }
}