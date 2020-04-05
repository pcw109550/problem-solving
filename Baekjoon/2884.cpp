#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int H, M; cin >> H >> M;
    if (M >= 45) { cout << H << ' '; }
    else { cout << (H == 0 && M < 45 ? 23 : H - 1) << ' '; }
    cout << (M + 15) % 60;
}