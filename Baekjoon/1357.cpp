#include <bits/stdc++.h>
using namespace std;

inline int Rev(int x) {
    string s = to_string(x);
    reverse(s.begin(), s.end());
    return stoi(s);
}

int main(void) {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int x, y; cin >> x >> y;
    cout << Rev(Rev(x) + Rev(y));
}