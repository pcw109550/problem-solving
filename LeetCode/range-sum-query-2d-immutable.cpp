// 304. Range Sum Query 2D - Immutable
#include <iostream>
#include <vector>

class NumMatrix {
    public:
        std::vector<std::vector<int> > D;
        NumMatrix(std::vector<std::vector<int> >& matrix) {
            // O(M * N)
            int M = matrix.size();
            if (M == 0)
                return;
            int N = matrix[0].size();
            D.emplace_back(std::vector<int> (N + 1, 0));
            std::vector<int> row;
            for (int i = 0; i < M; i++) {
                row.emplace_back(0);
                for (int j = 0; j < N; j++) {
                    row.emplace_back(row.back() + matrix[i][j] + D[i][j + 1] - D[i][j]);
                }
                D.emplace_back(row);
                row.clear();
            }
        }
        
        int sumRegion(int row1, int col1, int row2, int col2) {
            // O(1)
            return D[row2 + 1][col2 + 1] - D[row1][col2 + 1] - D[row2 + 1][col1] + D[row1][col1];
        }
};

int main(void) {
    std::vector<std::vector<int> > matrix = {{3, 0, 1, 4, 2},
        {5, 6, 3, 2, 1},
        {1, 2, 0, 1, 5},
        {4, 1, 0, 1, 7},
        {1, 0, 3, 0, 5}};
    NumMatrix* obj = new NumMatrix(matrix);
    int param_1 = obj->sumRegion(2, 1, 4, 3);
    std::cout << param_1 << std::endl;
    int param_2 = obj->sumRegion(1, 1, 2, 2);
    std::cout << param_2 << std::endl;
    int param_3 = obj->sumRegion(1, 2, 2, 4);
    std::cout << param_3 << std::endl;
}
