// 263. Ugly Number
#include <iostream>
using namespace std;

class Solution {
public:
    bool isUgly(int n) {
        // O(log(N))
        if (n <= 0)
            return false;
        while (true) {
            if (n % 2 == 0) {
                n /= 2;
                continue;
            }
            if (n % 3 == 0) {
                n /= 3;
                continue;
            }
            if (n % 5 == 0) {
                n /= 5;
                continue;
            }
            break;
        }
        return n == 1;
    }
};

int main(void) {
    Solution s;
}