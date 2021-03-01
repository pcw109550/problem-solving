// 934. Shortest Bridge
#include <iostream>
#include <vector>
#include <queue>
#include <utility>
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

class Solution {
    int M, N;
    std::vector<std::vector<bool> > visited;
    std::vector<std::vector<int> > distance;
    std::queue<std::pair<int, int> > border;
    public:
        int shortestBridge(std::vector<std::vector<int> >& A) {
            M = A.size(), N = A[0].size();
            visited = std::vector<std::vector<bool> >(M, std::vector<bool>(N, false));
            distance = std::vector<std::vector<int> >(M, std::vector<int>(N, 0));
            bool first = true;
            for (int i = 0; i < M && first; i++)
                for (int j = 0; j < N && first; j++) {
                    if (visited[i][j] || !A[i][j])
                        continue;
                    visited[i][j] = true;
                    std::queue<std::pair<int, int> > Q;
                    Q.push({i, j});
                    while (!Q.empty()) {
                        auto current = Q.front(); Q.pop();
                        if (first)
                            insert_if_border(A, current);
                        for (int dir = 0; dir < 4; dir++) {
                            int X = current.first + dx[dir];
                            int Y = current.second + dy[dir];
                            if (X < 0 || Y < 0 || X >= M || Y >= N)
                                continue;
                            if (!visited[X][Y] && A[X][Y]) {
                                visited[X][Y] = true;
                                Q.push({X, Y});
                            }
                        }
                    }
                    first = false;
                }
            while (!border.empty()) {
                auto current = border.front(); border.pop();
                for (int dir = 0; dir < 4; dir++) {
                    int X = current.first + dx[dir];
                    int Y = current.second + dy[dir];
                    if (X < 0 || Y < 0 || X >= M || Y >= N)
                        continue;
                    if (visited[X][Y])
                        continue;
                    if (A[X][Y])
                        return distance[current.first][current.second];
                    if (!A[X][Y]) {
                        visited[X][Y] = true;
                        distance[X][Y] = distance[current.first][current.second] + 1;
                        border.push({X, Y});
                    }
                }
            }
            return -1;      
        }
    
        inline void insert_if_border(std::vector<std::vector<int> > &A, std::pair<int, int> coord) {
            for (int dir = 0; dir < 4; dir++) {
                int X = coord.first + dx[dir];
                int Y = coord.second + dy[dir];
                if (X < 0 || Y < 0 || X >= M || Y >= N)
                    continue;
                if (!A[X][Y]) {
                    border.push(coord);
                    return;
                }
            }
        }
};

int main(void) {
    Solution s;
}