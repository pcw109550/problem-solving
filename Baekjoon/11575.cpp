#include<bits/stdc++.h>
using namespace std;

inline void task(void) {
    int a, b; string s;
    cin >> a >> b >> s;
    for (int i = 0; i < s.size(); i++) {
        s[i] = 'A' + ((s[i] - 'A') * a + b) % 26;
    }
    cout << s << '\n';
}

int main(void) {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--)
        task();
}   