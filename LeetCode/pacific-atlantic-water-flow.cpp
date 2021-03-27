// 417. Pacific Atlantic Water Flow
#include <iostream>
#include <vector>
#include <queue>
#include <utility>
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

class Solution {
    public:
        std::vector<std::vector<int> > pacificAtlantic(std::vector<std::vector<int> >& matrix) {
            // O(M * N)
            std::vector<std::vector<int> > result;
            int M = matrix.size();
            if (M == 0)
                return result;
            int N = matrix[0].size();
            std::queue<std::pair<int, int> > Q1, Q2;
            std::vector<std::vector<bool> > visited1 (M, std::vector<bool> (N, false));
            std::vector<std::vector<bool> > visited2 (M, std::vector<bool> (N, false));
            for (int i = 0; i < M; i++) {
                Q1.push({i, 0}); Q2.push({i, N - 1});
                visited1[i][0] = visited2[i][N - 1] = true;
            }
            for (int i = 0; i < N; i++) {
                Q1.push({0, i}); Q2.push({M - 1, i});
                visited1[0][i] = visited2[M - 1][i] = true;
            }
            travel(visited1, Q1, matrix);
            travel(visited2, Q2, matrix);
            for (int i = 0; i < M; i++)
                for (int j = 0; j < N; j++)
                    if (visited1[i][j] && visited2[i][j])
                        result.push_back(std::vector<int> {i, j});
            return result;
        }
    
        void travel(std::vector<std::vector<bool> >& visited, std::queue<std::pair<int, int> > &Q, 
                                                            std::vector<std::vector<int> >& matrix) {
            int M = matrix.size(), N = matrix[0].size();
            while (!Q.empty()) {
                auto current = Q.front(); Q.pop();
                for (int dir = 0; dir < 4; dir++) {
                    int X = current.first + dx[dir];
                    int Y = current.second + dy[dir];
                    if (X < 0 || Y < 0 || X >= M || Y >= N)
                        continue;
                    if (visited[X][Y])
                        continue;
                    if (!visited[X][Y] && matrix[X][Y] >= matrix[current.first][current.second]) {
                        Q.push({X, Y});
                        visited[X][Y] = true;
                    }
                }
            }   
        }
};

int main(void) {
    Solution s;
}