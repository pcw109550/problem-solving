#include <bits/stdc++.h>
using namespace std;

inline int check(string s) {
    stack<char> S; int cnt = 0, acc = 0, left = 0, right = 0;
    for (auto it = s.begin(); it != s.end(); it++) {
        if (*it == '{') { S.push('{'); left++; }
        else {
            if (!S.empty() && S.top() == '{') { S.pop(); left--; }
            else { S.push('}'); right++; }
        }
    }
    while (!S.empty()) {
        char it = S.top(); S.pop();
        if ((acc % 2 ? '}' : '{') == it) { cnt++; }
        acc++;
    }
    return cnt;
}

int main(void) {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    string s; int T = 1;
    while (true) {
        cin >> s;
        if (s.end() != find(s.begin(), s.end(), '-')) { return 0; }
        cout << T++ << ". " << check(s) << '\n';
    }
}