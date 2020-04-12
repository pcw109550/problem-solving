#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int x, y, w, h; cin >> x >> y >> w >> h;
    int result = min(x, min(w - x, min(y, h - y)));
    cout << result;
}