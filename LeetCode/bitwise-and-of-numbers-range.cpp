// 201. Bitwise AND of Numbers Range
#include <iostream>

class Solution {
    public:
        int rangeBitwiseAnd(int m, int n) {
            // O(log(N)
            unsigned int check = 1;
            unsigned int result = m;
            unsigned int N = n;
            while (check <= result) {
                if (check + result <= N && (result & check)) {
                    result -= check;
                }
                check <<= 1;
            }
            return static_cast<int>(result);
        }
};

int main(void) {
    Solution s;
    int result = s.rangeBitwiseAnd(2147483646, 2147483647);
    std::cout << result;
}