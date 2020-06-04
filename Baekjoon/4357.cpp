#include <bits/stdc++.h>
using namespace std;

template<typename T>
T powmod(T base, T exp, T mod) {
    __int128_t result = 1;
    while (exp > 0) {
        if (exp & 1) {
            result = ((__int128_t)base * result) % (__int128_t)mod;
        }
        exp >>= 1;
        base = ((__int128_t)base * base) % (__int128_t)mod; 
    }
    return (T)result;
}

template<typename T>
inline void BsGs(T P, T B, T N) {
    // O(sqrt(N))
    T m = (T)ceil(sqrt(P));
    unordered_map<T, T> table;
    __uint128_t e = 1;
    for (T i = 0; i < m; i++) {
        if (table.find((T)e) == table.end()) {
            // For finding minimal solution
            table[(T)e] = i;
        }
        e = (e * B) % P;
    }
    const T factor = powmod<T>(B, P - m - 1, P);
    e = N;
    for (T i = 0; i < m; i++) {
        if (auto it = table.find((T)e); it != table.end()) {
            T x = i * m + it->second;
            cout << x << '\n';
            return;
        }
        e = (e * factor) % P;
    }
    cout << "no solution\n";
}

int main(void) {
    ios::sync_with_stdio(false); cin.tie(NULL);
    uint32_t P, B, N;
    while (cin >> P >> B >> N) {
        BsGs<uint32_t>(P, B, N);
    }
}