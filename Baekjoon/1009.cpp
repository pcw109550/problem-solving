#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);
    int T, a, b, m, n, x; cin >> T;
    for (int i = 0; i < T; i++) {
        cin >> a >> b;        
        m = a % 2;                         // m = a ** b (mod 2)
        n = (a % 5 != 0);                  // n = a ** b (mod 5)
        for (int j = 0; j < b % 4; j++) { n *= a % 5; }
        x = (5 * m + 6 * n) % 10; // CRT
        cout << (x == 0 ? 10 : x) << '\n';
    }
}