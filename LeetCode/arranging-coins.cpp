// 441. Arranging Coins
#include <iostream>
using namespace std;

class Solution {
public:
    int arrangeCoins(int n) {
        // O(sqrt(N))
        int result = 0;
        long long c = 0;
        for (long long i = 1; i <= 1000000; i++) {
            c += i;
            if (n < c) {
                result = i - 1;
                break;
            }
        }
        return result;
    }
};

int main(void) {
    Solution s;
}