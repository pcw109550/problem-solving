// 1572. Matrix Diagonal Sum
#include <iostream>
#include <vector>

class Solution {
    public:
        int diagonalSum(std::vector<std::vector<int> >& mat) {
            // O(N)
            int sum = 0;
            int N = mat.size();
            for (int i = 0; i < N; i++) {
                sum += mat[i][i] + mat[i][N - i - 1];
            }
            if (N % 2)
                sum -= mat[N / 2][N / 2];
            return sum;
        }
};

int main(void) {
    Solution s;
}