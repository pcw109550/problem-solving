// 498. Diagonal Traverse
#include <algorithm>
#include <vector>
#include <iostream>

class Solution {
    public:
        std::vector<int> findDiagonalOrder(std::vector<std::vector<int> >& matrix) {
            // O(M * N)
            std::vector<int> result;
            int M = matrix.size();
            if (M == 0)
                return result;
            int N = matrix[0].size();
            if (N == 0)
                return result;
            int x, y, delta, cnt = 0;
            for (int i = 0; i < M + N - 1; i++) {
                if (i % 2 == 0) {
                    x = i; y = 0;
                    if (x >= M) {
                        delta = x - M + 1;
                        x = M - 1;
                        y = delta;
                    }
                    while (x >= 0 && y < N)
                        result.emplace_back(matrix[x--][y++]);
                } else {
                    x = 0; y = i;
                    if (y >= N) {
                        delta = y - N + 1;
                        x = delta;
                        y = N - 1;
                    }
                    while (y >= 0 && x < M)
                        result.emplace_back(matrix[x++][y--]);
                }
            }
            
            return result;
        }
};

int main(void) {
    Solution s;
}