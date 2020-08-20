#include <bits/stdc++.h>
using namespace std;
#define ITER 3

template<typename T>
T powmod(T base, T exp, T mod) {
    __int128_t result = 1;
    while (exp > 0) {
        if (exp & 1) {
            result = (static_cast<__int128_t>(base) * result) % static_cast<__int128_t>(mod);
        }
        exp >>= 1;
        base = (static_cast<__int128_t>(base) * base) % static_cast<__int128_t>(mod); 
    }
    return static_cast<T>(result);
}

template<typename T>
T powmod(T base, T exp) {
    __int128_t result = 1;
    while (exp > 0) {
        if (exp & 1) {
            result = static_cast<__int128_t>(base) * result;
        }
        exp >>= 1;
        base = static_cast<__int128_t>(base) * base;
    }
    return static_cast<T>(result);
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

template<typename T>
T PollardRho(T N) {
    if (N == 1)     { return 1; }
    if (N % 2 == 0) { return 2; }
    if (isPrime(N)) { return N; }
    T x, y, c, divisor = 1;
    srand(time(NULL));
    x = y = rand(); c = rand();
    while (divisor == 1) {
        x = (powmod<T>(x, 2, N) + c + N) % N;
        y = (powmod<T>(y, 2, N) + c + N) % N;
        y = (powmod<T>(y, 2, N) + c + N) % N;
        divisor = __gcd(abs(x - y), N);
        if (divisor == N) {
            x = y = rand(); c = rand();
            divisor = 1;
        }
    }
    return divisor;
}

template<typename T>
T euler_phi(T N) {
    T result = 1;
    queue<T> temp; temp.push(N);
    unordered_map<T, T> factor;
    while (!temp.empty()) {
        T current = temp.front(); temp.pop();
        if (isPrime(current)) {
            if (factor.find(current) == factor.end())
                factor[current] = 1;
            else
                factor[current]++;
        } else {
            T cand = PollardRho<T>(current);
            if (cand == 1) { continue; }
            temp.push(cand); temp.push(current / cand);
        }
    }
    for (auto it : factor) {
        T prime = it.first;
        T power = it.second;
        if (power == 1)
            result *= prime - 1;
        else
            result *= powmod<T>(prime, power - 1) * (prime - 1);
    }
    return result;
}

int main(void) {
    ios::sync_with_stdio(false); cin.tie(NULL);
    long long N; cin >> N;
    long long result = euler_phi<long long>(N);
    cout << result;
}