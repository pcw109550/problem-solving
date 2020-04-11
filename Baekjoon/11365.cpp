#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    string s;
    while (true) {
        getline(cin, s); if (!s.compare("END")) { return 0; }
        reverse(s.begin(), s.end());
        cout << s << '\n';
    }
}