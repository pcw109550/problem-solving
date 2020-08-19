#include<bits/stdc++.h>
using namespace std;
#define ITER 5

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
bool MillerRabin(T d, T N) {
    T a = 2 + rand() % (N - 4);
    T x = powmod<T>(a, d, N);
    if (x == 1 || x == N - 1) { return true; }
    while (d != N - 1) {
        x = powmod<T>(x, 2, N);
        d <<= 1;
        if (x == 1)     { return false; }
        if (x == N - 1) { return true;  }
    }
    return false;
}

template<typename T>
bool isPrime(T N) {
    if (N == 2 || N == 3)     { return true;  }
    if (N == 1 || N % 2 == 0) { return false; }
    T d = N - 1;
    while (!(d & 1)) { d >>= 1; }
    for (int i = 0; i < ITER; i++) {
        if (!MillerRabin<T>(d, N)) { return false;}
    }
    return true;
}

int main(void) {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    long long N, T;
    cin >> T;
    while (T--) {
        cin >> N;
        if (N <= 2) {
            cout << 2 << '\n';
            continue;
        }
        if (N % 2 == 0)
            N += 1;
        while (true) {
            if (isPrime<long long>(N)) {
                cout << N << '\n';
                break;
            }
            N += 2;
        }
    }
}   