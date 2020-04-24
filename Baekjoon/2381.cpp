#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int N, x, y; cin >> N;
    int addMax = -(1 << 30), addMin = 1 << 30, subMax = -(1 << 30), subMin = 1 << 30;
    for (int i = 0; i < N; i++) {
        cin >> x >> y;
        addMax = max(addMax, x + y);
        addMin = min(addMin, x + y);
        subMax = max(subMax, x - y);
        subMin = min(subMin, x - y);
    }
    cout << max(addMax - addMin, subMax - subMin);
}