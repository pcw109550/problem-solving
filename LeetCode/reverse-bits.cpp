// 190. Reverse Bits
#include <stdint.h>
#include <iostream>

class Solution {
    public:
        uint32_t reverseBits(uint32_t n) {
            // O(1)
            uint32_t res = 0;
            for (int i = 0; i < 32; i++) {
                res |= ((n & (1 << i)) >> i) << (31 - i);
            }
            return res;
        }
};

int main(void) {
    Solution s;
    uint32_t n = 0b00000010100101000001111010011100;
    std::cout << s.reverseBits(n);
}