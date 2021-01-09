// 292. Nim Game
#include <iostream>

class Solution {
    public:
        bool canWinNim(int n) {
            // O(1)
            return n % 4;
        }
};

int main(void) {
    Solution s;
}