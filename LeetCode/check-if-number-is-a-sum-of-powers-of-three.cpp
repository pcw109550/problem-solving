// 1780. Check if Number is a Sum of Powers of Three
#include <iostream>
#include <climits>

class Solution {
    public:
        bool checkPowersOfThree(int n) {
            // O(log(N))
            int c = 1;
            while (c < INT_MAX / 3)
                c *= 3;
            while (c) {
                if (c <= n) {
                    if (2 * c <= n)
                        return false;
                    n -= c;
                }
                c /= 3;
            }
            return true;
        }
};

int main(void) {
    Solution s;
}