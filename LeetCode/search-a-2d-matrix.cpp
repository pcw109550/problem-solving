// 74. Search a 2D Matrix
#include <algorithm>
#include <iostream>
#include <vector>

class Solution {
    public:
        bool searchMatrix(std::vector<std::vector<int>>& matrix, int target) {
            std::ios_base::sync_with_stdio(false);
            std::cin.tie(NULL);
            std::cout.tie(NULL);
            // O(M * N * log(N))
            int M = matrix.size();
            if (M == 0)
                return false;
            int N = matrix[0].size();
            if (N == 0)
                return false;
            for (int i = 0; i < M; i++)
                if (std::binary_search(matrix[i].begin(), matrix[i].end(), target))
                    return true;
            return false;
        }
};

int main(void) {
    Solution s;
    std::vector<std::vector<int> > matrix {{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 50}};
    std::cout << s.searchMatrix(matrix, 7) << std::endl;
}