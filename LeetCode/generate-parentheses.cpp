// 22. Generate Parentheses
#include <iostream>
#include <string>
#include <vector>

class Solution {
    std::vector<std::string> result;
    public:
        // O((4 ** N) / sqrt(N))
        std::vector<std::string> generateParenthesis(int n) {
            generate(0, 0, 2 * n, "");
            return result;
        }
    
        void generate(int l, int r, int total, std::string cand) {
            if (l + r == total && l == r) {
                result.emplace_back(cand);
                return;
            }
            if (l + r + 1 <= total) {
                if (l > r)
                    generate(l, r + 1, total, cand + ")");
                generate(l + 1, r, total, cand + "(");
            }
        }
};

int main(void) {
    Solution s;
    int n = 5;
    auto result = s.generateParenthesis(n);
    for (auto &it: result)
        std::cout << it << ' ';
}