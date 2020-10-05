// 476. Number Complement
#include <iostream>

class Solution {
    public:
        int findComplement(int num) {
            // O(1)
            int result = 0, i = 0;
            while (num > 0) {
                result |= !(num & 1) << i;
                num >>= 1;
                i += 1;
            }
            return result;
        }
};

int main(void) {
    Solution s;
    int num = 2147483647;
    int result = s.findComplement(num);
    std::cout << result;
}