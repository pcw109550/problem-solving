// 1342. Number of Steps to Reduce a Number to Zero
#include <iostream>

class Solution {
    public:
        int numberOfSteps (int num) {
            // O(log(N))
            int result = 0;
            while (num) {
                if (num % 2)
                    num--;
                else
                    num >>= 1;
                result++;
            }
            return result;
        }
};

int main(void) {
    Solution s;
}