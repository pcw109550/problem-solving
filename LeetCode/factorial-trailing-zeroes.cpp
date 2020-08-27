// 172. Factorial Trailing Zeroes
#include <iostream>

class Solution {
    public:
        int trailingZeroes(int n) {
            // O(log(N))
            if (n <= 4)
                return 0;
            int result = 0;
            for (long long i = 5; i <= static_cast<long long>(n); i *= 5) {
                result += n / i;
            }
            return result;
        }
};

int main(void) {
    Solution s;
    std::cout << s.trailingZeroes(120);
}