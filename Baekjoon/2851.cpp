#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int acc[11] = {}, temp, idx = 1, Min = 1 << 30;
    for (int i = 1; i <= 10; i++) {
        cin >> temp; acc[i] = acc[i - 1] + temp;
        int delta = abs(acc[i] - 100);
        if (delta <= Min) {
            Min = delta; idx = i;
        }
    }
    cout << acc[idx];
}