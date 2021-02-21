// 1091. Shortest Path in Binary Matrix
#include <iostream>
#include <vector>
#include <queue>
#include <utility>

int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

class Solution {
    public:
        int shortestPathBinaryMatrix(std::vector<std::vector<int> >& grid) {
            // O(M * N)
            if (grid[0][0] == 1)
                return -1;
            int M = grid.size(), N = grid[0].size();
            std::vector<std::vector<int> > visited (M, std::vector<int> (N, 0));
            std::queue<std::pair<int, int> > Q;
            Q.push({0, 0}); visited[0][0] = 1;
            while (!Q.empty()) {
                auto current = Q.front(); Q.pop();
                for (int dir = 0; dir < 8; dir++) {
                    int X = current.first + dx[dir];
                    int Y = current.second + dy[dir];
                    if (X < 0 || Y < 0 || X >= M || Y >= N)
                        continue;
                    if (grid[X][Y] == 0 && !visited[X][Y]) {
                        visited[X][Y] = visited[current.first][current.second] + 1;
                        Q.push({X, Y});
                        continue;
                    }
                }
            }
            return visited[M - 1][N - 1] == 0 ? -1 : visited[M - 1][N - 1];
        }
};

int main(void) {
    Solution s;
}