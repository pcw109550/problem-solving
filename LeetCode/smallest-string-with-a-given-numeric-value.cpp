// 1663. Smallest String With A Given Numeric Value
#include <iostream>
#include <string>

class Solution {
    public:
        std::string getSmallestString(int n, int k) {
            // O(log(N))
            std::string result (n, 'a');
            int cnt = k - n;
            for (int i = n - 1; i >= 0; i--) {
                if (cnt >= 25) {
                    result[i] = 'z';
                    cnt -= 25;
                } else {
                    result[i] += cnt;
                    break;
                }
            }
            return result;
        }
};

int main(void) {
    Solution s;
}