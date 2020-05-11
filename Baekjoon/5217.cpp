#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T, a; cin >> T;
    while (T--) {
        cin >> a;
        cout << "Pairs for " << a << ':';
        for (int i = 1; i <= a >> 1; i++) {
            if (i << 1 != a) {
                cout << ' ' << i << ' ' << a - i;
            }
            if (i != a >> 1 && (i + 1) << 1 != a) { cout << ','; }
        }
        cout << '\n';
    }
}