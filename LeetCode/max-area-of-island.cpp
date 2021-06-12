// 695. Max Area of Island
#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <utility>

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

class Solution {
    public:
        int maxAreaOfIsland(std::vector<std::vector<int>>& grid) {
            // O(N)
            int result = 0;
            int M = grid.size(), N = grid[0].size();
            std::vector<std::vector<bool> > visited(M, std::vector<bool>(N, false));
            for (int i = 0; i < M; i++)
                for (int j = 0; j < N; j++) {
                    if (visited[i][j])
                        continue;
                    if (grid[i][j] == 0) {
                        visited[i][j] = true;
                        continue;
                    }
                    int area = 1;
                    std::queue<std::pair<int, int> > Q;
                    visited[i][j] = true;
                    Q.push({i, j});
                    while (!Q.empty()) {
                        auto cur = Q.front(); Q.pop();
                        for (int dir = 0; dir < 4; dir++) {
                            int X = cur.first + dx[dir];
                            int Y = cur.second + dy[dir];
                            if (X < 0 || Y < 0 || X >= M || Y >= N)
                                continue;
                            if (grid[X][Y] == 0)
                                continue;
                            if (grid[X][Y] == 1 && !visited[X][Y]) {
                                Q.push({X, Y});
                                visited[X][Y] = true;
                                area++;
                            }
                        }
                    }
                    result = std::max(result, area);
                }
            return result;    
        }
};

int main(void) {
    Solution s;
}