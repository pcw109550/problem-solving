// 1690. Stone Game VII
#include <algorithm>
#include <iostream>
#include <vector>

class Solution {
    public:
        int stoneGameVII(std::vector<int>& stones) {
            // O(N ** 2)
            int result = 0;
            int N = stones.size();
            std::vector<std::vector<int> > D (N + 2, std::vector<int>(N + 2, 0));
            std::vector<int> ps (N + 1, 0);
            for (int i = 0; i < N; i++)
                ps[i + 1] = ps[i] + stones[i]; 
            for (int size = 1; size <= N; size++)
                for (int i = 1, j = size; j <= N; i++, j++) {
                    int parity = (i + j + N) % 2;
                    if (parity == 1)
                        D[i][j] = std::max((ps[j] - ps[i]) + D[i + 1][j], (ps[j - 1] - ps[i - 1]) + D[i][j - 1]);
                    else
                        D[i][j] = std::min(-(ps[j] - ps[i]) + D[i + 1][j], -(ps[j - 1] - ps[i - 1]) + D[i][j - 1]);
                }
            result = D[1][N];
            return result;
        }
};

int main(void) {
    Solution s;
}