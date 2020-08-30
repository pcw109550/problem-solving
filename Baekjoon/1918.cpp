#include<bits/stdc++.h>
using namespace std;
string s;

inline bool isop(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}

inline int level(char c) {
    if (c == '+' || c == '-')
        return 1;
    if (c == '*' || c == '+')
        return 2;
}

pair<string, int> postfix(int idx) {
    stack<char> op;
    stack<string> val;
    for (int i = idx; i < s.size(); i++) {
        if (!isop(s[i])) {
            if (!op.empty() && (op.top() == '*' || op.top() == '/') && s[i] != '(') {
                auto current = val.top(); val.pop();
                current += string (1, s[i]);
                current += string (1, op.top()); op.pop();
                val.push(current);
            } else {
                if (s[i] == '(') {
                    auto result = postfix(i + 1);
                    if (!op.empty() && (op.top() == '*' || op.top() == '/')) {
                        auto current = val.top(); val.pop();
                        current += result.first;
                        current += string (1, op.top()); op.pop();
                        val.push(current);
                    } else {
                        val.push(result.first);
                    }
                    i += result.second + 1;
                } else if (s[i] == ')') {
                    while (!op.empty()) {
                        auto r = val.top(); val.pop();
                        auto l = val.top(); val.pop();
                        auto currop = op.top(); op.pop();
                        val.push(l + r + string (1, currop));  
                    }
                    return {val.top(), i - idx};
                } else {
                    val.push(string (1, s[i]));
                }
            }
        } else {
            if (!op.empty() && level(op.top()) == level(s[i])) {
                auto r = val.top(); val.pop();
                auto l = val.top(); val.pop();
                auto currop = op.top(); op.pop();
                val.push(l + r + string (1, currop));
            }
            op.push(s[i]);
        }
    }

    while (!op.empty()) {
        auto r = val.top(); val.pop();
        auto l = val.top(); val.pop();
        auto currop = op.top(); op.pop();
        val.push(l + r + string (1, currop));  
    }
    return {val.top(), 0};
}

int main(void) {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cin >> s;
    auto result = postfix(0);
    cout << result.first;
}   