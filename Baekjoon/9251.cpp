#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);
    string s1, s2; cin >> s1 >> s2;
    int Max = 0;
    if (s1.length() > s2.length()) { swap(s1, s2); }
    int D1[s1.length()] = {}, D2[s1.length()] = {};
    for (int i = 0; i < s2.length(); i++) { // O(N * M)
        int cnt = 0;
        for (int j = 0; j < s1.length(); j++) {
            if (s2[i] == s1[j]) {
                D2[j] = cnt + 1;
            }
            cnt = max(cnt, D1[j]);
            Max = max(Max, D2[j]);
        }
        for (int j = 0; j < s1.length(); j++) {
            D1[j] = D2[j];
        }
    }
    cout << Max;
}