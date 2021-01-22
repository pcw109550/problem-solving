// 7. Reverse Integer
#include <iostream>
#define INT_MAX 2147483647
#define INT_MIN -2147483648

class Solution {
    public:
        int reverse(int x) {
            // O(log(N))
            if (x == INT_MIN)
                return 0;
            int result = 0;
            bool sign = x < 0;
            if (sign)
                x = -x;
            while (x > 0) {
                if (result > INT_MAX / 10)
                    return 0;
                result *= 10;
                if (result > INT_MAX - x + sign)
                    return 0;
                result += x % 10;
                x /= 10;
            }
            if (sign)
                result = -result;
            return result;
        }
};

int main(void) {
    Solution s;
}