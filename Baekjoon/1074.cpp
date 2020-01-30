#include <bits/stdc++.h>
using namespace std;

int rec(int n, int r, int c) {
    int half = 1 << (n - 1);
    int base = 0;
    if (c >= half) { base += half * half;     c -= half; }
    if (r >= half) { base += half * half * 2; r -= half; }
    if (n == 1) { return base; }
    return base + rec(n - 1, r, c);
}

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);
    int N, r, c; cin >> N >> r >> c;
    cout << rec(N, r, c);
}