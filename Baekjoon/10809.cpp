#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);
    string s; int current; cin >> s; int D[26]; fill(D, D + 26, -1);
    for (int i = 0; i < s.length(); i++) {
        current = s[i] - 'a';
        if (D[current] == -1) { D[current] = i; }
    }
    for (int i = 0; i < 26; i++) {
        cout << D[i] << " ";
    }
}