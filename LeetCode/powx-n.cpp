// 50. Pow(x, n)
#include <iostream>

class Solution {
    public:
        double myPow(double x, int n) {
            // O(log(N))
            long long N = n;
            double result = 1;
            if (N < 0) {
                x = 1 / x;
                N = -N;
            }
            double q = x;
            while (N) {
                if (N & 1)
                    result *= q;
                N >>= 1;
                q *= q;
            }
            return result;
        }
};

int main(void) {
    Solution s;
}