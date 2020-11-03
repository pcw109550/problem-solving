// 1446. Consecutive Characters
#include <iostream>
#include <string>

class Solution {
    public:
        int maxPower(std::string s) {
            // O(N)
            int result = 0, acc = 0;
            char c = '\0';
            for (auto &elem: s) {
                if (elem == c) {
                    acc++;
                } else {
                    c = elem;
                    result = std::max(result, acc);
                    acc = 1;
                }
            }
            result = std::max(result, acc);
            return result;
        }
};

int main(void) {
    Solution s;
    std::string str("y");
    int result = s.maxPower(str);
    std::cout << result;
}