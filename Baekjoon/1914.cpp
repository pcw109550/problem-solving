#include <bits/stdc++.h>
using namespace std;

string to_string(__int128_t x) {
    string s;
    while (x > 0) {
        s.push_back(x % 10 + '0');
        x /= 10;
    }
    reverse(s.begin(), s.end());
    return s;
}

void hanoi(int src, int dst, int n) {
    if (n == 0) { return; }
    hanoi(src, 6 - src - dst, n - 1);
    cout << src << ' ' << dst << '\n';
    hanoi(6 - src - dst, dst, n - 1);   
}

int main(void) {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int N; cin >> N; __int128_t result = 1;
    for (int i = 0; i < N; i++) {
        result <<= 1;
    }
    result -= 1;
    cout << to_string(result) << '\n';
    if (N > 20) { return 0; }
    hanoi(1, 3, N);
}