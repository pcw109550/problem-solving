#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    string s; int ans;
    while (true) {
        getline(cin, s); if (s[0] == '#') { return 0; }
        ans = 0;
        for (auto it = s.begin(); it != s.end(); it++) {
            char c = *it;
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
                c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') {
                ans++;
            }
        }
        cout << ans << '\n';
    }
}