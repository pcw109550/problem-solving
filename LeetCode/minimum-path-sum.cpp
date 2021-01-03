// 64. Minimum Path Sum
#include <iostream>
#include <vector>

class Solution {
    public:
        int minPathSum(std::vector<std::vector<int> >& grid) {
            // O(M * N)
            int M = grid.size();
            int N = grid[0].size();
            int D[200][200] = {};
            for (int i = 0; i < M; i++) {
                for (int j = 0; j < N; j++) {
                    if (i == 0 && j == 0)
                        D[i][j] = 0;
                    else if (i == 0)
                        D[i][j] = D[i][j - 1];
                    else if (j == 0)
                        D[i][j] = D[i - 1][j];
                    else   
                        D[i][j] = std::min(D[i - 1][j], D[i][j - 1]);
                    D[i][j] += grid[i][j];
                }
            }
            return D[M - 1][N - 1];
        }
};

int main(void) {
    Solution s;
}