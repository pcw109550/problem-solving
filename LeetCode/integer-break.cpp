// 343. Integer Break
#include <iostream>

class Solution {
    public:
        int integerBreak(int n) {
            // O(N) using AM-GM inequality
            int Max = -1, tempMax, q, r;
            for (int i = 2; i <= n; i++) {
                tempMax = 1;
                q = n / i;
                r = n % i;
                for (int j = 0; j < i; j++) {
                    tempMax *= (j < r ? q + 1: q);
                }
                if (Max <= tempMax)
                    Max = tempMax;
                else
                    break;
            }
            return Max;
        }
};

int main(void) {
    Solution s;
    int result = s.integerBreak(57);
    std::cout << result;   
}