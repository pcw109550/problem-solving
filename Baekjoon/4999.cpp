#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    string s1, s2; cin >> s1 >> s2;
    cout << (s1.length() >= s2.length() ? "go" : "no");  
}