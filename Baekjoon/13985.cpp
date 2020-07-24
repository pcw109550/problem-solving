#include<bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    string s;
    getline(cin, s);
    cout << (s[0] + s[4] - '0' == s[8] ? "YES" : "NO");
}