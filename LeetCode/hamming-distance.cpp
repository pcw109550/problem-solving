// 461. Hamming Distance
#include <iostream>

class Solution {
    public:
        int hammingDistance(int x, int y) {
            return __builtin_popcount(x ^ y);
        }
};

int main(void) {
    Solution s;
    int result = s.hammingDistance(1, 4);
    std::cout << result;
}