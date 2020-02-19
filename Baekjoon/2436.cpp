#include <bits/stdc++.h>
using namespace std;

inline int gcdcal(int a, int b) {
    int t;
    while (b != 0) {
        t = a % b; a = b; b = t;
    }
    return a;
}

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);
    int gcd, lcm, x, y, X, Y, temp, min = 3 * (1 << 29); cin >> gcd >> lcm;
    int N = lcm / gcd; // lcm = gcd * x * y where gcd(x, y) == 1
    for (int i = 1; i * i <= N; i++) {
        if (N % i == 0) {
            x = i; y = N / i;
            if (gcdcal(x, y) == 1) { temp = x + y;
                if (temp < min) { min = temp; X = x; Y = y;}
            }
        }
    }
    cout << gcd * X << " " << gcd * Y;
}