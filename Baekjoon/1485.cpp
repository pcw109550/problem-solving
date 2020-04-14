#include <bits/stdc++.h>
using namespace std;

inline long long square(int x) { return (long long)x * x; }

int main(void) {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T; int x[4] = {}, y[4] = {};
    for (int t = 0; t < T; t++) {
        for (int i = 0; i < 4; i++) {
            cin >> x[i] >> y[i];
        }
        long long examine[6] = {}; int cnt = 0; bool issquare = true;
        for (int i = 0; i < 4; i++) {
            for (int j = i + 1; j < 4; j++) {
                int dist = square(x[i] - x[j]) + square(y[i] - y[j]);
                if (dist == 0) { cout << 0 << '\n'; issquare = false; break; }
                examine[cnt++] = dist;
            }
            if (!issquare) { break; }
        }
        if (issquare) {
            sort(examine, examine + 6);
            if (examine[0] == examine[1] && examine[1] == examine[2] && examine[2] == examine[3] && \
                    examine[4] == 2 * examine[0] && examine[4] == examine[5]) {
                    cout << 1 << '\n';
            } else {
                cout << 0 << '\n';
            }
        }
    }
}