#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);
    string s; int N; getline(cin, s); N = stoi(s);
    int charset[26] = {};
    for (int i = 0; i < N; i++) {
        getline(cin, s);
        charset[s[0] - 'a']++;
    }
    bool found = false;
    for (int i = 0; i < 26; i++) {
        if (charset[i] >= 5) { found = true; cout << (char)(i + 'a'); }
    }
    if (!found) { cout << "PREDAJA"; }

}