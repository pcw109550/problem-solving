// 1015. Smallest Integer Divisible by K
#include <iostream>
using namespace std;

class Solution {
public:
    int smallestRepunitDivByK(int k) {
        // O(k)
        int sum = 0;
        int c = 1;
        for (int i = 1; i <= k; i++) {
            sum = (sum + c) % k;
            if (sum == 0)
                return i;
            c = 10 * c % k;
        }
        return -1;
    }
};

int main(void) {
    Solution s;
}