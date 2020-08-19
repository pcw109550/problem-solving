// 342. Power of Four
#include <iostream>

class Solution {
    public:
        bool isPowerOfFour(int num) {
            if (num == 0)
                return false;
            int cnt = 31 - __builtin_clz(num);
            bool result = (cnt % 2 == 0) && ((1 << cnt) == num);
            return result;
        }
};

class Solution2 {
    public:
        bool isPowerOfFour(int num) {
            int cnt = -1;
            int temp = num;
            while (temp > 0) {
                cnt++;
                temp >>= 1;
            }
            bool result = (cnt % 2 == 0) && ((1 << cnt) == num);
            return result;
        }
};

int main(void) {
    Solution s;
    bool result = s.isPowerOfFour(16 * 16 + 1);
    std::cout << result;
}