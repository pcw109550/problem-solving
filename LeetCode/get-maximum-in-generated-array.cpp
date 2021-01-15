// 1646. Get Maximum in Generated Array
#include <algorithm>
#include <iostream>
#include <vector>

class Solution {
    public:
        int getMaximumGenerated(int n) {
            // O(N)
            if (n <= 1)
                return n;
            int result = 1;
            std::vector<int> D(n + 1, 0);
            D[1] = 1;
            for (int i = 2; i <= n; i++) {
                if (i % 2 == 0)
                    D[i] = D[i / 2];
                else
                    D[i] = D[i / 2] + D[i / 2 + 1];
                result = std::max(result, D[i]);
            }
            return result;
        }
};

int main(void) {
    Solution s;
}