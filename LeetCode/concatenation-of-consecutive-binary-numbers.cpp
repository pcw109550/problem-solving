// 1680. Concatenation of Consecutive Binary Numbers
#include <iostream>
#define FIELD 1000000007L

class Solution {
    public:
        int concatenatedBinary(int n) {
            // O(N)
            unsigned long long result = 0;
            int width = 1, cnt = 0, shift = 1;
            for (int i = 1; i <= n; i++) {
                cnt++;
                result <<= shift;
                result |= i;
                result %= FIELD;
                if (width == cnt) {
                    width <<= 1;
                    cnt = 0;
                    shift++;
                }
            }
            return result;
        }
};

int main(void) {
    Solution s;
}