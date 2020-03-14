#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);
    int N, x, y, d[5] = {}; cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> x >> y;
        if (x * y == 0) { d[4]++; }
        else if (y > 0) {
            if (x > 0) { d[0]++; }
            if (x < 0) { d[1]++; }
        } else {
            if (x < 0) { d[2]++; }
            if (x > 0) { d[3]++; }
        }
    }
    for (int i = 0; i < 5; i++) {
        if (i == 4) { cout << "AXIS: " << d[4]; }
        else { cout << "Q" << i + 1 << ": " << d[i]; }
        cout << '\n';
    }
}