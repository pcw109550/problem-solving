// 63. Unique Paths II
#include <iostream>
#include <vector>

class Solution {
    public:
        int uniquePathsWithObstacles(std::vector<std::vector<int>>& obstacleGrid) {
            // O(M * N)
            int result = 0;
            int M = obstacleGrid.size();
            int N = obstacleGrid[0].size();
            if (M == 1 && N == 1)
                return !obstacleGrid[0][0];
            std::vector<std::vector<int> > D (M, std::vector<int> (N, 0));
            D[0][0] = 1;
            for (int i = 0; i < M; i++)
                for (int j = 0; j < N; j++) {
                    if (obstacleGrid[i][j])
                        continue;
                    if (i >= 1 && !obstacleGrid[i - 1][j])
                        D[i][j] += D[i - 1][j];
                    if (j >= 1 && !obstacleGrid[i][j - 1])
                        D[i][j] += D[i][j - 1];
                }
            result = D[M - 1][N - 1];
            return result;
        }
};

int main(void) {
    Solution s;
}