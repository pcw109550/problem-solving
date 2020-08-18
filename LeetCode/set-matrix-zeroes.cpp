// 73. Set Matrix Zeroes
#include <cstdio>
#include <iostream>
#include <vector>

#define ENCODE 1 << 30

class Solution {
    public:
        void setZeroes(std::vector<std::vector<int> >& matrix) {
            std::ios_base::sync_with_stdio(false);
            std::cin.tie(NULL);
            std::cout.tie(NULL);
            // O(1) space, O(N * M) time
            int N = matrix.size();
            int M = matrix[0].size();   
            for (int i = 0; i < N; i++) {
                bool is_zero = false;
                for (int j = 0; j < M; j++)
                    is_zero |= matrix[i][j] == 0;
                if (is_zero)
                    for (int j = 0; j < M; j++)
                        matrix[i][j] = matrix[i][j] == 0 ? ENCODE : 0;
            }
            for (int j = 0; j < M; j++) {
                bool is_zero = false;
                for (int i = 0; i < N; i++)
                    is_zero |= matrix[i][j] == ENCODE;
                if (is_zero)
                    for (int i = 0; i < N; i++)
                        matrix[i][j] = 0;
            }
        }
};

int main(void) {
    Solution s;
    std::vector<std::vector<int> > matrix {{0, 1, 2, 0}, {3, 4, 5, 2}, {1, 3, 1, 5}};
    s.setZeroes(matrix);
    for (auto row : matrix) {
        for (auto elem : row)
            std::cout << elem << ' ';
        std::cout << std::endl;
    }
}