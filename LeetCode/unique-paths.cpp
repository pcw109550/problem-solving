// 62. Unique Paths
#include <iostream>

class Solution {
    public:
        int uniquePaths(int m, int n) {
            // O(M * N)
            int D[100][100] = {};
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    if (i == 0 || j == 0) {
                        D[i][j] = 1;
                        continue;
                    }
                    D[i][j] = D[i - 1][j] + D[i][j - 1];
                }
            }
            return D[m - 1][n - 1];
        }
};

int main(void) {
    Solution s;
    int result = s.uniquePaths(1, 1);
    std::cout << result;
}