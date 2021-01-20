// 678. Valid Parenthesis String
#include <deque>
#include <iostream>
#include <stack>
#include <string>
#include <utility>

class Solution {
    public:
        bool checkValidString(std::string s) {
            // O(N)
            std::stack<std::pair<char, int> > S;
            std::deque<int> wildcard;
            for (int i = 0; i < s.size(); i++) {
                if (s[i] == '(')
                    S.push({'(', i});
                else if (s[i] == ')') {
                    if (!S.empty() && S.top().first == '(')
                        S.pop();
                    else
                        S.push({')', i});
                } else
                    wildcard.push_back(i);
            }
            if (S.empty())
                return true;
            while (!S.empty()) {
                if (wildcard.empty())
                    return false;
                if (S.top().first == '(') {
                    if (S.top().second < wildcard.back()) {
                        S.pop();
                        wildcard.pop_back();
                    } else
                        return false;
                } else {
                    if (S.top().second > wildcard.front()) {
                        S.pop();
                        wildcard.pop_front();
                    } else
                        return false;
                }
            }
            return S.empty();
        }
};

int main(void) {
    Solution s;
}