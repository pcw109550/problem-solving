#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);
    int T, a, b; cin >> T;
    for (int i = 0; i < T; i++) {
        cin >> a >> b; int gcd = __gcd(a, b);
        cout << a * b / gcd << ' ' << gcd << '\n';
    }
}