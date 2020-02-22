#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);
    string s; cin >> s; sort(s.begin(), s.end(), greater<char>());
    cout << s;
}