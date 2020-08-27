// 20. Valid Parentheses
#include <cassert>
#include <iostream>
#include <stack>
#include <string>

class Solution {
    public:
        bool isValid(std::string s) {
            // O(N)
            std::stack<char> S;
            for (auto c : s) {
                if (c == '(' || c == '{' || c == '[')
                    S.push(c);
                else {
                    if (S.empty())
                        return false;
                    auto top = S.top();
                    switch(c) {
                        case ')':
                            if (top != '(')
                                return false;
                            break;
                        case '}':
                            if (top != '{')
                                return false;
                            break;
                        case ']':
                            if (top != '[')
                                return false;
                            break;
                        default:
                            assert(false);
                            break;
                    }
                    S.pop();
                }
            }
            return S.empty();
        }
};

int main(void) {
    Solution s;
    std::string str ("()()()()");
    std::cout << s.isValid(str);
}