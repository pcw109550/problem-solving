#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int x[3] = {}; cin >> x[0] >> x[1] >> x[2];
    sort(x, x + 3);
    int d1 = x[1] - x[0], d2 = x[2] - x[1];
    if (d1 == d2) { cout << x[2] + d1; }
    else {
        cout << (d1 < d2 ? x[1] + d1 : x[0] + d2);
    }
}