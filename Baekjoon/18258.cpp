#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);
    string s; getline(cin, s); int N = stoi(s); queue<int> Q;
    for (int i = 0 ; i < N; i++) {
        getline(cin, s);
        if (!s.compare(0, 4, "push")) {
            Q.push(stoi(&s[5]));
        } else if (!s.compare(0, 3, "pop")) {
            if (Q.empty()) { cout << -1 << '\n'; }
            else { cout << Q.front() << '\n'; Q.pop(); }
        } else if (!s.compare(0, 4, "size")) {
            cout << Q.size() << '\n';
        } else if (!s.compare(0, 5, "empty")) {
            cout << Q.empty() << '\n';
        } else if (!s.compare(0, 5, "front")) {
            if (Q.empty()) { cout << -1 << '\n'; }
            else { cout << Q.front() << '\n'; }
        } else if (!s.compare(0, 4, "back")) {
            if (Q.empty()) { cout << -1 << '\n'; }
            else { cout << Q.back() << '\n'; }
        }
    }
}