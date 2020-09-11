// 221. Maximal Square
#include <iostream>
#include <utility>
#include <vector>

class Solution {
    public:
        int maximalSquare(std::vector<std::vector<char> >& matrix) {
            // O(N * M)
            int N = matrix.size();
            if (N == 0)
                return 0;
            int M = matrix[0].size();
            if (M == 0)
                return 0;
            int Max = 0, result;
            std::vector<std::vector<int> > D {static_cast<unsigned int>(N + 1), std::vector<int> (M + 1, 0)};
            for (int i = 0; i <= N; i++) {
                for (int j = 0; j <= M; j++) {
                    if (i == 0 || j == 0 || matrix[i - 1][j - 1] == '0')
                        continue;
                    D[i][j] = std::min(std::min(D[i - 1][j], D[i][j - 1]), D[i - 1][j - 1]) + 1;
                    Max = std::max(Max, D[i][j]);
                }
            }            
            result = Max * Max;
            return result;
        }
};

int main(void) {
    Solution s;
    std::vector<std::vector<char > > matrix {{'1', '1', '1', '1', '0'},
        {'1', '1', '1', '1', '1'},
        {'1', '1', '1', '1', '1'},
        {'1', '1', '1', '1', '0'}};
    int result = s.maximalSquare(matrix);
    std::cout << result;
}
