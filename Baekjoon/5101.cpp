#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);
    int a, b, c;
    while (true) {
        cin >> a >> b >> c; if (a == 0 && b == 0 && c == 0) { return 0; }
        if ((c - a) % b == 0) { cout << (c - a) / b + 1 << '\n'; } else { cout << "X\n"; }
    }
}