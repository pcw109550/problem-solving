#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    bool is31[12] = {true, false, true, false, true, false, true, true, false, true, false, true};
    string Day[7] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};
    int x, y, acc = 0; cin >> x >> y; acc = --y;
    for (int i = 1; i < x; i++) {
        acc += (i == 2 ? 28 : (is31[i - 1] ? 31 : 30));
    }
    cout << Day[acc % 7];
}