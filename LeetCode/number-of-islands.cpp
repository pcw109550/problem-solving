// 200. Number of Islands
#include <iostream>
#include <queue>
#include <utility>
#include <vector>

class Solution {
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};
    public:
        int numIslands(std::vector<std::vector<char> >& grid) {
            std::ios_base::sync_with_stdio(false);
            std::cin.tie(NULL);
            std::cout.tie(NULL);
            // O(M * N) BFS
            int result = 0;
            int M = grid.size();
            if (M == 0)
                return 0;
            int N = grid[0].size();
            if (N == 0)
                return 0;
            std::queue<std::pair<int, int> > Q;
            for (int i = 0; i < M; i++) {
                for (int j = 0; j < N; j++) {
                    if (grid[i][j] == '1') {
                        result++;
                        grid[i][j] = '2'; // Encode as visited
                        Q.push({i, j});
                        while (!Q.empty()) {
                            auto current = Q.front(); Q.pop();
                            for (int dir = 0; dir < 4; dir++) {
                                int X = current.first + dx[dir];
                                int Y = current.second + dy[dir];
                                if (X < 0 || Y < 0 || X >= M || Y >= N)
                                    continue;
                                if (grid[X][Y] == '1') {
                                    grid[X][Y] = '2';
                                    Q.push({X, Y});
                                }
                            }
                        }
                    }
                }
            }
            return result;
        }
};

class Solution2 {
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};
    public:
        int numIslands(std::vector<std::vector<char> >& grid) {
            // O(M * N) BFS
            int result = 0;
            int M = grid.size();
            if (M == 0)
                return 0;
            int N = grid[0].size();
            if (N == 0)
                return 0;
            std::vector<std::vector<bool> > visited;
            for (int i = 0; i < M; i++)
                visited.emplace_back(std::vector<bool> (N, false));
            std::queue<std::pair<int, int> > Q;
            for (int i = 0; i < M; i++) {
                for (int j = 0; j < N; j++) {
                    if (!visited[i][j] && grid[i][j] == '1') {
                        result++;
                        visited[i][j] = true;
                        Q.push({i, j});
                        while (!Q.empty()) {
                            auto current = Q.front(); Q.pop();
                            for (int dir = 0; dir < 4; dir++) {
                                int X = current.first + dx[dir];
                                int Y = current.second + dy[dir];
                                if (X < 0 || Y < 0 || X >= M || Y >= N)
                                    continue;
                                if (!visited[X][Y] && grid[X][Y] == '1') {
                                    visited[X][Y] = true;
                                    Q.push({X, Y});
                                }
                            }
                        }
                    }
                }
            }
            return result;
        }
};

int main(void) {
    Solution s;
    std::vector<std::vector<char> > grid {{'1', '1', '0', '0', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '1', '0', '0'},
        {'0', '0', '0', '1', '1'}};
    int result = s.numIslands(grid);
    std::cout << result;
}