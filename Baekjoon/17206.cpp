#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);
    int T, temp, x, y, z, result; cin >> T;
    for (int t = 0; t < T; t++) {
        cin >> temp; x = temp / 3; y = temp / 7; z = temp / 21;
        result = 3 * x * (x + 1) / 2;
        result += 7 * y * (y + 1) / 2;
        result -= 21 * z * (z + 1) / 2;
        cout << result << '\n';
    }
}