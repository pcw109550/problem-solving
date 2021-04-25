// 1074. Number of Submatrices That Sum to Target
#include <vector>
#include <unordered_map>

class Solution {
    public:
        int numSubmatrixSumTarget(std::vector<std::vector<int> >& matrix, int target) {
            // O(M ** 2 * N)
            int result = 0;
            int M = matrix.size(), N = matrix[0].size();
            std::vector<std::vector<int> > D (M + 1, std::vector<int> (N + 1, 0));
            for (int i = 1; i <= M; i++)
                for (int j = 1; j <= N; j++) {
                    D[i][j] += matrix[i - 1][j - 1];
                    D[i][j] += D[i - 1][j];
                    D[i][j] += D[i][j - 1];
                    D[i][j] -= D[i - 1][j - 1];
                }
            for (int r1 = 0; r1 <= M; r1++) {
                for (int r2 = r1 + 1; r2 <= M; r2++) {
                    std::unordered_map<int, int> Map;
                    Map[0] = 1;
                    int s = 0;
                    for (int c = 1; c <= N; c++) {
                        s += (D[r2][c] - D[r1][c]) - (D[r2][c - 1] - D[r1][c - 1]) ;
                        result += Map[s - target];
                        Map[s] += 1;
                    }
                }
            }
            return result;
        }
};

class Solution2 {
    public:
        int numSubmatrixSumTarget(std::vector<std::vector<int> >& matrix, int target) {
            // O(M ** 2 * N ** 2)
            int result = 0;
            int M = matrix.size(), N = matrix[0].size();
            std::vector<std::vector<int> > D (M + 1, std::vector<int> (N + 1, 0));
            for (int i = 1; i <= M; i++)
                for (int j = 1; j <= N; j++) {
                    D[i][j] += matrix[i - 1][j - 1];
                    D[i][j] += D[i - 1][j];
                    D[i][j] += D[i][j - 1];
                    D[i][j] -= D[i - 1][j - 1];
                }
            for (int r1 = 0; r1 <= M; r1++) {
                for (int r2 = r1 + 1; r2 <= M; r2++) {
                    for (int c1 = 0; c1 <= N; c1++) {
                        for (int c2 = c1 + 1; c2 <= N; c2++){
                            int sub = D[r2][c2] - D[r1][c2] - D[r2][c1] + D[r1][c1];
                            if (sub == target)
                                result++;
                        }
                    }
                }
            }
            return result;
        }
};

int main(void) {
    Solution s;
}