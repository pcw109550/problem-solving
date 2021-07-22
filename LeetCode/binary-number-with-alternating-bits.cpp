// 693. Binary Number with Alternating Bits
#include <iostream>
using namespace std;

class Solution {
public:
    bool hasAlternatingBits(int n) {
        // O(log(N))
        bool prev = n & 1;
        n >>= 1;
        while (n > 0) {
            if ((n & 1) == prev)
                return false;
            n >>= 1;
            prev = !prev;
        }
        return true;
    }
};

int main(void) {
    Solution s;
}