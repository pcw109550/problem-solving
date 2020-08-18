// 70. Climbing Stairs
#include <iostream>

class Solution {
    public:
        int climbStairs(int n) {
            // O(n)
            int D[46] = {};
            D[1] = 1;
            D[2] = 2;
            for (int i = 3; i <= n; i++)
                D[i] = D[i - 1] + D[i - 2];
            return D[n];
        }
};

int main(void) {
    Solution s;
    for (int i = 1; i <= 45; i++)
        std::cout << s.climbStairs(i) << std::endl;
}