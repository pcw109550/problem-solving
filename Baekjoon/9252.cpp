#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);
    string s1, s2; cin >> s1 >> s2;
    short Max = 0, Maxloc;
    if (s1.length() > s2.length()) { swap(s1, s2); }
    short D1[s1.length()] = {}, D2[s1.length()] = {};
    short D3[s2.length()][s1.length()] = {};
    for (int i = 0; i < s2.length(); i++) { // O(N * M)
        short cnt = 0, loc = 0;;
        for (int j = 0; j < s1.length(); j++) {
            if (s2[i] == s1[j]) {
                D2[j] = cnt + 1;
                if (D2[j] > 1) { D3[i][j] = loc; }
            }
            cnt = max(cnt, D1[j]);
            if (cnt == D1[j]) { loc = j + 1; }
            Max = max(Max, D2[j]);
            if (Max == D2[j]) { Maxloc = j; }
        }
        for (int j = 0; j < s1.length(); j++) {
            D1[j] = D2[j];
        }
    }
    cout << Max << '\n';
    if (!Max) { return 0; }
    int idx = Maxloc; bool updated = true;
    vector<char> result;
    for (int i = s2.length() - 1; i >= 0; i--) {
        if (updated && idx >= 0) {
            result.push_back(s1[idx]);
        }
        if (D3[i][idx]) {
            idx = D3[i][idx] - 1;
            updated = true;
        } else {
            updated = false;
        }
    }
    reverse(result.begin(), result.end());
    for (auto it = result.begin(); it != result.end(); it++) {
        cout << *it;
    }
}