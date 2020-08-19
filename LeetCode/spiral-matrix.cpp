// 54. Spiral Matrix
#include <iostream>
#include <vector>

class Solution {
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};
    public:
        std::vector<int> spiralOrder(std::vector<std::vector<int> >& matrix) {
            // Space O(1) Time O(M * N)
            int M = matrix.size();
            if (M == 0)
                return std::vector<int> ();
            int N = matrix[0].size();
            if (N == 0)
                return std::vector<int> ();
            std::vector<int> result;
            int dir = 0;
            int x1 = 0, x2 = N - 1;
            int y1 = 0, y2 = M - 1;
            while (x1 <= x2 && y1 <= y2) {
                for (int x = x1; x <= x2; x++)
                    result.emplace_back(matrix[y1][x]);
                for (int y = y1 + 1; y <= y2; y++)
                    result.emplace_back(matrix[y][x2]);
                if (x1 < x2 && y1 < y2) {
                    for (int x = x2 - 1; x > x1; x--)
                        result.emplace_back(matrix[y2][x]);
                    for (int y = y2; y > y1; y--)
                        result.emplace_back(matrix[y][x1]);
                }
                y1++; y2--;
                x1++; x2--;
            }
            return result;
        }
};

class Solution2 {
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};
    public:
        std::vector<int> spiralOrder(std::vector<std::vector<int> >& matrix) {
            // Space O(M * N) Time O(M * N)
            int M = matrix.size();
            if (M == 0)
                return std::vector<int> ();
            int N = matrix[0].size();
            if (N == 0)
                return std::vector<int> ();
            std::vector<int> result;
            std::vector<std::vector<bool> > visited;
            for (int i = 0; i < M; i++)
                visited.emplace_back(std::vector<bool> (N, false));
            int nx, ny, acc = 1, x = 0, y = 0, dir = 0;
            while (acc++ <= M * N) {
                result.emplace_back(matrix[y][x]);
                visited[y][x] = true;
                ny = y + dy[dir];
                nx = x + dx[dir];
                if (nx < 0 || ny < 0 || nx >= N || ny >= M || visited[ny][nx])
                    dir = (dir + 1) % 4;
                y = y + dy[dir];
                x = x + dx[dir];
            }
            return result;
        }
};

int main(void) {
    Solution s;
    std::vector<std::vector<int> > matrix {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    std::vector<int> result = s.spiralOrder(matrix);
    for (auto it : result) {
        std::cout << it << ' ';
    }
}