#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false); cin.tie(NULL);
    string s; cin >> s; char prev; int result = 10;
    for (int i = 0; i < s.length(); i++) {
        if (i > 0) {
            if (prev == s[i]) { result += 5; }
            else              { result += 10;}
        }
        prev = s[i];
    }
    cout << result;
}