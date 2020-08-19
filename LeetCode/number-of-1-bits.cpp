// 191. Number of 1 Bits
#include <cstdint>
#include <iostream>

class Solution {
    public:
        int hammingWeight(uint32_t n) {
            int result = 0;
            // O(log(n))
            while (n > 0) {
                result += static_cast<int>(n & 1);
                n >>= 1;
            }
            return result;;
        }
};

int main(void) {
    Solution s;
    int result = s.hammingWeight(0b00);
    std::cout << result;
}