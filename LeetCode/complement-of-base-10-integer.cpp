// 1009. Complement of Base 10 Integer
#include <iostream>

class Solution {
    public:
        int bitwiseComplement(int N) {
            // O(1)
            if (N == 0)
                return 1;
            int result = 0, i = 0;
            while (N > 0) {
                result |= !(N & 1) << i;
                N >>= 1;
                i += 1;
            }
            return result;            
        }
};

int main(void) {
    Solution s;
    int N = 0;
    int result = s.bitwiseComplement(N);
    std::cout << result;
}