#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    string s; bool balanced;
    while (true) {
        getline(cin, s); balanced = true;
        if (!s.compare(".")) { return 0; }
        stack<char> S;
        for (auto it = s.begin(); it != s.end(); it++) {
            if (*it == '(' || *it == '[') {
                S.push(*it);
            } else if (*it == ')') {
                if (S.empty() || S.top() != '(') { balanced = false; break; }
                else { S.pop(); }
            } else if (*it == ']') {
                if (S.empty() || S.top() != '[') { balanced = false; break; }
                else { S.pop(); }
            }
        }
        cout << ( S.empty() && balanced ? "yes" : "no") << '\n';
    }    
}