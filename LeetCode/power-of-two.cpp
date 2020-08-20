// 231. Power of Two
#include <iostream>

class Solution {
    public:
        bool isPowerOfTwo(int n) {
            return n >= 0 && __builtin_popcount(n) == 1;            
        }
};

int main(void) {
    Solution s;
    std::cout << s.isPowerOfTwo(256);
}