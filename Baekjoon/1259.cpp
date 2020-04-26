#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    string s; bool isPalindrome;
    while (true) {
        cin >> s;
        isPalindrome = true;
        if (!s.compare("0")) { return 0; }
        for (int i = 0; i < s.length() / 2 + 1; i++) {
            if (s[i] != s[s.length() - i - 1]) { isPalindrome = false; }
        }
        cout << (isPalindrome ? "yes" : "no") << '\n';
    }
}