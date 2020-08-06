#include <bits/stdc++.h>
using namespace std;

inline bool is_palindrome(int n) {
    int a = n, b = 0;
    while (a > 0) {
        b *= 10;
        b += a % 10;
        a /= 10;
    }
    return b == n;
}

inline bool is_prime(int n) {
    if (n == 1)
        return false;
    for (int i = 2; i * i <= n; i++)
        if (!(n % i))
            return false;
    return true;
}

int main(void) {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int N; cin >> N;
    int probe = N;
    if (N == 1 || N == 2) {
        cout << 2;
        return 0;
    }
    if (!(probe % 2))
        probe++;
    while (true) {
        if (is_palindrome(probe) && is_prime(probe))
            break;
        probe += 2;
    }
    cout << probe;
}