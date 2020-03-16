#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);
    int a, b, c;
    while (true) {
        cin >> a >> b >> c; if (a == 0 && b == 0 && c == 0) { return 0; }
        if ((c - a) % b == 0) {
            int output = (c - a) / b + 1;
            if (output >= 1) { cout << output << '\n'; } else { cout << "X\n"; }    
        } else { cout << "X\n"; }
    }
}