// 507. Perfect Number
#include <iostream>

class Solution {
    public:
        bool checkPerfectNumber(int num) {
            // O(sqrt(N))
            int acc = 0;
            for (int i = 1; i * i <= num; i++)
                if (num % i == 0) {
                    if (i != num)
                        acc += i;
                    if (i * i != num && num / i != num)
                        acc += num / i;
                }
            return acc == num;
        }
};

int main(void) {
    Solution s;
}