#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int alphabet[26] = {}; string s;
    getline(cin, s); int Max = -1;
    for (auto it = s.begin(); it != s.end(); it++) {
        Max = max(Max, ++alphabet[*it <= 'Z' ? *it - 'A' : *it - 'a']);
    }
    int cnt = 0, idx;
    for (int i = 0; i < 26; i++) {
        if (Max == alphabet[i]) { cnt++; idx = i; }
    }
    cout << (cnt == 1 ? (char)(idx + 'A') : '?');
}