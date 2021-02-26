// 856. Score of Parentheses
#include <iostream>
#include <string>

class Solution {
    int pos = 0;
    std::string s;
    public:
        int scoreOfParentheses(std::string S) {
            // O(N)
            s = S;
            int result = 0;
            while (pos < S.size()) {
                result += iterate();
            }
            return result;
        }
    
        int iterate() {
            int result = 0;
            if (s[pos++] == '(') {
                while (s[pos] == '(') {
                    result += 2 * iterate();
                }
                if (s[pos] == ')') {
                    pos++;
                    result = result == 0 ? 1 : result;
                }
            }
            return result;
        }
};

int main(void) {
    Solution s;
}