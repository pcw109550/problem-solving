// 367. Valid Perfect Square
#include <iostream>

class Solution {
    public:
        bool isPerfectSquare(int num) {
            long long lo = 1, hi = num;
            while (lo <= hi) {
                long long mid = lo + (hi - lo) / 2;
                if (mid * mid == num)
                    return true;
                else if (mid * mid > num) {
                    hi = mid - 1;
                } else if (mid * mid < num) {
                    lo = mid + 1;
                }
            }
            return false;
        }
};

int main(void) {
    Solution s;
    int num = 17;
    std::cout << s.isPerfectSquare(num);
}