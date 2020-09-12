// 240. Search a 2D Matrix II
#include <algorithm>
#include <iostream>
#include <vector>

class Solution {
    public:
        bool searchMatrix(std::vector<std::vector<int> >& matrix, int target) {
            // O(N + M)
            bool result = false;
            if (matrix.size() == 0)
                return false;
            if (matrix[0].size() == 0)
                return false;
            int N = matrix.size(), M = matrix[0].size();
            int i = 0, j = M - 1;
            while (i < N && j >= 0) {
                if (matrix[i][j] == target)
                    return true;
                else if (matrix[i][j] > target)
                    j--;
                else if (matrix[i][j] < target)
                    i++;
                else
                    return true;
            }
            return false;
        }
};

class Solution2 {
    public:
        bool searchMatrix(std::vector<std::vector<int> >& matrix, int target) {
            // O(N * log(M))
            bool result = false;
            if (matrix.size() == 0)
                return false;
            if (matrix[0].size() == 0)
                return false;
            for (int i = 0; i < matrix.size(); i++)
                if (std::binary_search(matrix[i].begin(), matrix[i].end(), target))
                    return true;
            return false;
        }
};

int main(void) {
    Solution s;
    std::vector<std::vector<int> > matrix {{1, 4, 7, 11},
                                            {2, 5, 8, 12},
                                            {3, 6, 9, 16},
                                            {10, 13, 14, 17},
                                            {18, 21, 23, 26},
                                            {31, 32, 33, 34}};
    int target = 9;
    bool result = s.searchMatrix(matrix, target);
    std::cout << result;

}