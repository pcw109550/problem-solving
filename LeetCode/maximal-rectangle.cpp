// 85. Maximal Rectangle
#include <algorithm>
#include <iostream>
#include <vector>
#include <unordered_map>

class Solution {
    public:
        int maximalRectangle(std::vector<std::vector<char> >& matrix) {
            // O(M ** 2 * N)
            int result = 0;
            int M = matrix.size();
            if (M == 0)
                return result;
            int N = matrix[0].size();
            std::vector<std::vector<int> > D (M + 1, std::vector<int>(N + 1, 0));
            for (int i = 1; i <= M; i++)
                for (int j = 1; j <= N; j++) {
                    D[i][j] = D[i - 1][j] + D[i][j - 1] - D[i - 1][j - 1];
                    D[i][j] += matrix[i - 1][j - 1] == '1';
                }
            for (int i = 1; i <= M; i++)
                for (int j = i; j <= M; j++) {
                    int sum = 0;
                    for (int k = 1; k <= N; k++) {
                        int temp = D[j][k] - D[i - 1][k] - D[j][k - 1] + D[i - 1][k - 1];
                        if (temp == j - i + 1) {
                            sum += temp;
                            result = std::max(result, sum);
                        } else
                            sum = 0;
                    }
                }
            return result;
        }
};

class Solution2 {
    public:
        int maximalRectangle(std::vector<std::vector<char> >& matrix) {
            // O(M ** 2 * N ** 2)
            int result = 0;
            int M = matrix.size();
            if (M == 0)
                return result;
            int N = matrix[0].size();
            std::vector<std::vector<int> > D (M + 1, std::vector<int>(N + 1, 0));
            for (int i = 1; i <= M; i++)
                for (int j = 1; j <= N; j++) {
                    D[i][j] = D[i - 1][j] + D[i][j - 1] - D[i - 1][j - 1];
                    D[i][j] += matrix[i - 1][j - 1] == '1';
                }
            for (int i = 1; i <= M; i++)
                for (int j = i; j <= M; j++)
                    for (int k = 1; k <= N; k++)
                        for (int l = k; l <= N; l++) {
                            int t1 = D[j][l] - D[i - 1][l] - D[j][k - 1] + D[i - 1][k - 1];
                            int t2 = (j - i + 1) * (l - k + 1);
                            if (t1 == t2)
                                result = std::max(result, t1);
                        }
            return result;
        }
};

int main(void) {
    Solution s;
}