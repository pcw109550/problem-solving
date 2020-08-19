// 59. Spiral Matrix II
#include <iostream>
#include <vector>

class Solution {
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};
    public:
        std::vector<std::vector<int> > generateMatrix(int n) {
            // O(n ** 2)
            std::vector<std::vector<int> > matrix;
            int nx, ny, acc = 1, x = 0, y = 0, dir = 0;
            for (int i = 0; i < n; i++)
                matrix.emplace_back(std::vector<int> (n, 0));
            while (acc <= n * n) {
                matrix[y][x] = acc++;
                ny = y + dy[dir];
                nx = x + dx[dir];
                if (nx < 0 || ny < 0 || nx >= n || ny >= n || matrix[ny][nx] != 0)
                    dir = (dir + 1) % 4;
                y = y + dy[dir];
                x = x + dx[dir];
            }
            return matrix;
        }
};

int main(void) {
    Solution s;
    auto matrix = s.generateMatrix(3);
    for (auto row : matrix) {
        for (auto elem : row)
            std::cout << elem << ' ';
        std::cout << std::endl;
    }
}