// 1137. N-th Tribonacci Number
#include <iostream>

class Solution {
    public:
        int tribonacci(int n) {
            // O(N)
            int D[3] = {0, 1, 1};
            if (n <= 2)
                return D[n];
            for (int i = 0; i <= n - 3; i++) {
                int temp = D[0] + D[1] + D[2];
                D[0] = D[1];
                D[1] = D[2];
                D[2] = temp;
            }
            return D[2];
        }
};

int main(void) {
    Solution s;
}