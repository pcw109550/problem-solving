#include <bits/stdc++.h>
using namespace std;
inline bool check(char a, char b) {
    int temp = (a - '0') * 10 + (b - '0');
    return 1 <= temp && temp <= 26;
}

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);
    string s; cin >> s; int l = s.length(); int D[l] = {};
    if (s[0] == '0') { cout << 0; return 0; } D[0] = 1;
    if (l >= 2) {
        if (s[1] == '0' && check(s[0], s[1])) { D[1] = 1; }
        if (s[1] == '0' && !check(s[0], s[1])) { cout << 0; return 0; }
        if (s[1] != '0' && check(s[0], s[1])) { D[1] = 2; }
        if (s[1] != '0' && !check(s[0], s[1])) { D[1] = 1; }
    }
    for (int i = 2; i < l; i++) {
        if (s[i - 1] == '0' && s[i] == '0') { cout << 0; return 0; }
        if (s[i - 1] == '0' && s[i] != '0') { D[i] = D[i - 1]; }
        if (s[i - 1] != '0' && s[i] == '0') {
            if (check(s[i - 1], s[i])) { D[i] = D[i - 2]; }
            else { cout << 0; return 0; }
        }
        if (s[i - 1] != '0' && s[i] != '0') {
            D[i] = (D[i - 1] + (check(s[i - 1], s[i]) ? D[i - 2] : 0)) % 1000000;
        }
    }
    cout << D[l - 1];
}