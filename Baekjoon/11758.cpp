#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int x[3] = {}, y[3] = {};
    for (int i = 0; i < 3; i++) { cin >> x[i] >> y[i]; }
    int x1 = x[1] - x[0], y1 = y[1] - y[0];
    int x2 = x[2] - x[1], y2 = y[2] - y[1];
    int result = x1 * y2 - x2 * y1; // Cross product
    if (result == 0) { cout << 0; return 0; }
    cout << (result > 0 ? 1 : -1);
}