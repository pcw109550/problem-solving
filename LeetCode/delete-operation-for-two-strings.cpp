// 583. Delete Operation for Two Strings
#include <algorithm>
#include <iostream>
#include <vector>

class Solution {
    public:
        int minDistance(std::string word1, std::string word2) {
            // O(M * N)
            int M = word1.size(), N = word2.size();
            int Max = 0;
            std::vector<std::vector<int> > D (M + 1, std::vector<int> (N + 1, 0));
            for (int i = 1; i <= M; i++)
                for (int j = 1; j <= N; j++) {
                    if (word1[i - 1] == word2[j - 1])
                        D[i][j] = D[i - 1][j - 1] + 1;
                    else
                        D[i][j] = std::max(D[i - 1][j], D[i][j - 1]);
                    Max = std::max(Max, D[i][j]);
                }
            return M + N - 2 * Max;
        }
};

int main(void) {
    Solution s;
}