// 1631. Path With Minimum Effort
#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#define INF 1 << 30
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

class Solution {
    int M, N;
    public:
        int minimumEffortPath(std::vector<std::vector<int> >& heights) {
            // Dijkstra O(M * N * log(M * N))
            M = heights.size();
            N = heights[0].size();
            std::vector<std::vector<int> > D(M, std::vector<int>(N, INF));
            D[0][0] = 0;
            std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int> >, std::greater<std::pair<int, int> > > PQ;
            PQ.push({0, encode(0, 0)});
            while (!PQ.empty()) {
                auto current = PQ.top(); PQ.pop();
                int distance = current.first;
                auto pos = decode(current.second);
                if (D[pos.first][pos.second] == distance) {
                    for (int dir = 0; dir < 4; dir++) {
                        int X = pos.first + dx[dir];
                        int Y = pos.second + dy[dir];
                        if (X < 0 || Y < 0 || X >= M || Y >= N)
                            continue;
                        int weight = std::abs(heights[X][Y] - heights[pos.first][pos.second]);
                        if (D[X][Y] > std::max(distance, weight)) {
                            D[X][Y] = std::max(distance, weight);
                            PQ.push({D[X][Y], encode(X, Y)});
                        }
                    }
                }
            }
            return D[M - 1][N - 1];     
        }
    
        inline int encode(int i, int j) {
            return i * N + j;
        }
    
        inline std::pair<int, int> decode(int c) {
            return {c / N, c % N};
        }
};

int main(void) {
    Solution s;
}