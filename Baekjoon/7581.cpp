#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);
    int a, b, c, V;
    while (true) {
        cin >> a >> b >> c >> V;
        if (a == 0 && b == 0 && c == 0 && V == 0) { return 0; }
        if (a == 0) {
            cout << V / (b * c) << " " << b << " " << c << " " << V << '\n';
        } else if (b == 0) {
            cout << a << " " << V / (a * c) << " " << c << " " << V << '\n';
        } else if (c == 0) {
            cout << a << " " << b << " " << V / (a * b) << " " << V << '\n';
        } else {
            cout << a << " " << b << " " << c << " " << a * b * c << '\n';
        }
    }
}