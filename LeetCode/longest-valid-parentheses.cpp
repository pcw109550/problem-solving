// 32. Longest Valid Parentheses
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

class Solution {
    public:
        int longestValidParentheses(std::string s) {
            // O(N)
            int result = 0;
            int N = s.size();
            std::vector<int> D(N, 0);
            for (int i = 1; i < N; i++) {
                if (s[i] == ')' && i - D[i - 1] - 1 >= 0 && s[i - D[i - 1] - 1] == '(') {
                    D[i] = 2 + D[i - 1];
                    if (i - D[i] >= 0)
                        D[i] += D[i - D[i]];
                }
                result = std::max(result, D[i]);
            }
            return result;
        }
};

int main(void) {
    Solution s;
}