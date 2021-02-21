// 991. Broken Calculator
#include <iostream>

class Solution {
    public:
        int brokenCalc(int X, int Y) {
            // O(log(N))
            int result = 0;
            while (Y > X) {
                result++;
                if (Y % 2 == 1)
                    Y++;
                else
                    Y /= 2;
            }
            result += X - Y;
            return result;
        }
};

int main(void) {
    Solution s;
}