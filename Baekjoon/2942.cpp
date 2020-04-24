#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int R, G; cin >> R >> G;
    int gcd = __gcd(R, G);
    for (int i = 1; i * i <= gcd; i++) {
        if (!(gcd % i)) {
            cout << i << ' ' << R / i << ' ' << G / i << '\n';
            if (i * i != gcd) {
                cout << gcd / i << ' ' << (R / gcd) * i << ' ' << (G / gcd) * i << '\n';
            }
        }
    }
}