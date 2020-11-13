// 69. Sqrt(x)
#include <iostream>

class Solution {
    public:
        int mySqrt(int x) {
            // log(N)
            if (x <= 1)
                return x;
            long long lo = 0, hi = static_cast<long long>(x), mid;
            while (lo < hi) {
                mid = lo + (hi - lo) / 2;
                if (mid * mid == x)
                    return mid;
                if (mid * mid > x) {
                    hi = mid;
                } else {
                    if ((mid + 1) * (mid + 1) > x)
                        return mid;
                    lo = mid;
                }
            }
            return mid - 1;
        }
};

int main(void) {
    Solution s;
    int x = 8;
    std::cout << s.mySqrt(x);
}