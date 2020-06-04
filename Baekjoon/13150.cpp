#include <bits/stdc++.h>
using namespace std;

inline __int128_t readBigInt() {
    __int128_t result = 0; string s; cin >> s;
    for (auto it : s) {
        result = 10 * result + it - '0';
    }
    return result;
}

int main(void) {
    ios::sync_with_stdio(false); cin.tie(NULL);
    __int128_t a[4]; char result[121] = {}; int probe = 0;
    for (int i = 0; i < 4; i++) { a[i] = readBigInt(); }
    while (!(a[0] == 1 && a[1] == 0 && a[2] == 0 && a[3] == 1)) {
        if (a[0] >= a[1] && a[2] >= a[3]) {
            result[probe] = '0';
            a[0] -= a[1];
            a[2] -= a[3];
        } else {
            result[probe] = '1';
            a[1] -= a[0];
            a[3] -= a[2];
        }
        probe++;
    }
    for (int i = 0; i < probe; i++) {
        cout << result[probe - i - 1];
    }
}