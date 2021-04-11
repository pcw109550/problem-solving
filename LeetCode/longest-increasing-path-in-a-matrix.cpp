// 329. Longest Increasing Path in a Matrix
#include <iostream>
#include <vector>
#include <queue>
#include <utility>

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

class Solution {
    int M, N;
    public:
        int longestIncreasingPath(std::vector<std::vector<int> >& matrix) {
            // Topological sort O(M * N)
            M = matrix.size(), N = matrix[0].size();
            std::vector<std::vector<std::vector<std::pair<int, int> > > > edge (M, std::vector<std::vector<std::pair<int, int> > >(N, std::vector<std::pair<int, int> >()));
            std::vector<std::vector<int> > indegree(M, std::vector<int>(N, 0));
            for (int i = 0; i < M; i++)
                for (int j = 0; j < N; j++)
                    for (int dir = 0; dir < 4; dir++) {
                        int X = i + dx[dir];
                        int Y = j + dy[dir];
                        if (X < 0 || Y < 0 || X >= M || Y >= N)
                            continue;
                        if (matrix[i][j] > matrix[X][Y]) {
                            edge[i][j].push_back({X, Y});
                            indegree[X][Y]++;
                        }
                    }
            std::queue<std::pair<int, std::pair<int, int> > > Q;
            for (int i = 0; i < M; i++)
                for (int j = 0; j < N; j++) {
                    if (!indegree[i][j])
                        Q.push({1, {i, j}});
                }
            int result = 1;
            while (!Q.empty()) {
                auto current = Q.front(); Q.pop();
                int trace = current.first;
                int curX = current.second.first, curY = current.second.second;
                for (auto it : edge[curX][curY]) {
                    indegree[it.first][it.second]--;
                    if (!indegree[it.first][it.second])
                        Q.push({trace + 1, {it.first, it.second}});
                    result = std::max(result, trace + 1);
                }
            }
            return result;
        }
};

class Solution2 {
    int M, N;
    public:
        int longestIncreasingPath(std::vector<std::vector<int> >& matrix) {
            // O(N ** 4)
            M = matrix.size(), N = matrix[0].size();
            int result = 0;
            std::vector<std::vector<int> > dist(M, std::vector<int>(N, 0));
            for (int i = 0; i < M; i++)
                for (int j = 0; j < N; j++) {
                    dist[i][j] = track(i, j, matrix);
                    result = std::max(result, dist[i][j]);
                }
            return result;
        }
    
        int track(int x, int y, std::vector<std::vector<int> >& matrix) {
            std::vector<std::vector<int> > visited(M, std::vector<int>(N, 0));
            std::queue<std::pair<int, int> > Q;
            Q.push({x, y}); visited[x][y] = 1;
            int Max = 1;
            while (!Q.empty()) {
                auto current = Q.front(); Q.pop();
                for (int dir = 0; dir < 4; dir++) {
                    int X = current.first + dx[dir];
                    int Y = current.second + dy[dir];
                    if (X < 0 || Y < 0 || X >= M || Y >= N)
                        continue;
                    if (matrix[X][Y] > matrix[current.first][current.second]) {
                        visited[X][Y] = visited[current.first][current.second] + 1;
                        Max = std::max(Max, visited[X][Y]);
                        Q.push({X, Y});
                    }
                }
            }
            return Max;
        } 
};

int main(void) {
    Solution s;
}