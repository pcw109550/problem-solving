// 829. Consecutive Numbers Sum
#include <iostream>

class Solution {
    public:
        int consecutiveNumbersSum(int N) {
            // O(sqrt(N))
            int result = 0;
            int n = 2 * N;
            // Different parity
            for (int i = 1; i * i <= n; i++)
                if (n % i == 0 && ((n / i) ^ i) & 1 == 1)
                    result++;
            return result;
        }
};

int main(void) {
    Solution s;
    int result = s.consecutiveNumbersSum(4);
    std::cout << result;
}