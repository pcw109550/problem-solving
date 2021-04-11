// 1551. Minimum Operations to Make Array Equal
#include <iostream>

class Solution {
    public:
        int minOperations(int n) {
            // O(1)
            return (n / 2) * (n / 2 + n % 2);
        }
};

int main(void) {
    Solution s;
}