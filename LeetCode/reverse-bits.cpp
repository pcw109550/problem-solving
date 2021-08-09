// 190. Reverse Bits
#include <stdint.h>
#include <iostream>

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        // O(1)
        n = ((n & 0xFFFF0000) >> 16) | ((n & 0x0000FFFF) << 16);
        n = ((n & 0xFF00FF00) >>  8) | ((n & 0x00FF00FF) <<  8);
        n = ((n & 0xF0F0F0F0) >>  4) | ((n & 0x0F0F0F0F) <<  4);
        n = ((n & 0xCCCCCCCC) >>  2) | ((n & 0x33333333) <<  2);
        n = ((n & 0xAAAAAAAA) >>  1) | ((n & 0x55555555) <<  1);
        return n;
    }
};

class Solution2 {
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