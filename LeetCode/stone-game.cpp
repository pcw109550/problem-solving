// 877. Stone Game
#include <algorithm>
#include <iostream>
#include <vector>

class Solution {
    public:
        bool stoneGame(std::vector<int>& piles) {
            // O(1)
            return true;
        }
};

class Solution2 {
    public:
        bool stoneGame(std::vector<int>& piles) {
            // O(N ** 2)
            int N = piles.size();
            std::vector<std::vector<int> > D (N + 2, std::vector<int>(N + 2, 0));
            for (int size = 1; size <= N; size++)
                for (int i = 1, j = size; j <= N; i++, j++) {
                    int parity = (i + j + N) % 2;
                    if (parity == 1)
                        D[i][j] = std::max(piles[i - 1] + D[i + 1][j], piles[j - 1] + D[i][j - 1]);
                    else
                        D[i][j] = std::min(-piles[i - 1] + D[i + 1][j], -piles[j - 1] + D[i][j - 1]);
                }
            return D[1][N] > 0;
        }
};

int main(void) {
    Solution s;
}