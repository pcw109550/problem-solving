// 1716. Calculate Money in Leetcode Bank
#include <iostream>
using namespace std;

class Solution {
    public:
        int totalMoney(int n) {
            // O(1)
            int r = n % 7;
            int q = n / 7;
            int result = 0;
            result += 7 * q * (q - 1) / 2;
            result += 7 * 8 / 2 * q;
            result += r * q + r * (r + 1) / 2;
            return result;
        }
};

int main(void) {
    Solution s;
}