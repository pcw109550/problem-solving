// 72. Edit Distance
#include <algorithm>
#include <iostream>
#include <string>

class Solution {
    public:
        int minDistance(std::string word1, std::string word2) {
            int m = word1.size(), n = word2.size();
            int D[501][501] = {};
            for (int i = 0; i <= m; i++)
                D[i][0] = i;
            for (int j = 0; j <= n; j++)
                D[0][j] = j;
            for (int i = 1; i <= m; i++)
                for (int j = 1; j <= n; j++)
                    D[i][j] = std::min(std::min(D[i - 1][j] + 1, D[i][j - 1] + 1), D[i - 1][j - 1] + static_cast<int>(word1[i - 1] != word2[j - 1]));
            int result = D[m][n];
            return result;
        }
};

int main(void) {
    Solution s;
    std::string word1 ("horse"), word2 ("ros");
    int result = s.minDistance(word1, word2);
    std::cout << result;
}