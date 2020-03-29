#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int call[3] = {30, 35, 40}, data[3] = {40, 30, 20};
    int x, y;
    while (true) {
        cin >> x >> y; if (x == 0 && y == 0) { return 0; }
        int Min = 1 << 30;
        for (int i = 0; i < 3; i++) {
            Min = min(Min, call[i] * x + data[i] * y);
        }
        cout << Min << '\n';
    }
}