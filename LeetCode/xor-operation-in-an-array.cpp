// 1486. XOR Operation in an Array
#include <iostream>

class Solution {
    public:
        int xorOperation(int n, int start) {
            // O(N)
            int result = 0;
            for (int i = 0; i < n; i++)
                result ^= (start + 2 * i);
            return result;
        }
};

int main(void) {
    Solution s;
}