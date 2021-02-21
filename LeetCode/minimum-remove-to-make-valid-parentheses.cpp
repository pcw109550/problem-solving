// 1249. Minimum Remove to Make Valid Parentheses
#include <iostream>
#include <string>
#include <stack>
#include <unordered_set>
#include <cctype>

class Solution {
    public:
        std::string minRemoveToMakeValid(std::string s) {
            // O(N)
            std::stack<int> S;
            std::string result;
            std::unordered_set<int> pos;
            int N = s.size();
            for (int i = 0; i < N; i++) {
                if (s[i] == '(')
                    S.push(i);
                else if (s[i] == ')' && !S.empty()) {
                    pos.insert(S.top());
                    S.pop();
                    pos.insert(i);
                }
            }
            for (int i = 0; i < N; i++)
                if (std::isalpha(s[i]) || pos.count(i))
                    result.push_back(s[i]);
            return result;
        }
};

int main(void) {
    Solution s;
}