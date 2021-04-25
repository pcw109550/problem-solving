// 150. Evaluate Reverse Polish Notation
#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <cctype>

class Solution {
    public:
        int evalRPN(std::vector<std::string>& tokens) {
            // O(N)
            int result = 0;
            std::stack<int> S;
            for (auto token : tokens) {
                if (std::isdigit(token[token.size() - 1]))
                    S.push(std::stoi(token));
                else {
                    int a = S.top(); S.pop();
                    int b = S.top(); S.pop();
                    switch (token[0]) {
                        case '+':
                            S.push(b + a);
                            break;
                        case '-':
                            S.push(b - a);
                            break;
                        case '*':
                            S.push(b * a);
                            break;
                        case '/':
                            S.push(b / a);
                            break;
                        default:
                            break;
                    }
                }
            }
            result = S.top(); S.pop();
            return result;
        }
};

int main(void) {
    Solution s;
}