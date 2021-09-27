// 1293. Shortest Path in a Grid with Obstacles Elimination
#include <algorithm>
#include <iostream>
#include <vector>
#include <climits>
#include <queue>
#include <utility>
using namespace std;

class Solution {
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};
    int D[40][40][40 * 40 + 1];
    bool visited[40][40][40 * 40 + 1];
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        // O(M * N * K)
        int result = INT_MAX;
        int M = grid.size();
        int N = grid[0].size();
        for (int step = 0; step <= k; step++) {
            queue<pair<int, int> > Q;
            Q.push({0, 0}); visited[0][0][step] = true;
            while (!Q.empty()) {
                auto cur = Q.front(); Q.pop();
                for (int dir = 0; dir < 4; dir++) {
                    int X = cur.first + dx[dir];
                    int Y = cur.second + dy[dir];
                    if (X < 0 || X >= M || Y < 0 || Y >= N)
                        continue;
                    if (grid[X][Y] == 0) {
                        if (visited[cur.first][cur.second][step] && (!visited[X][Y][step] || D[X][Y][step] > D[cur.first][cur.second][step] + 1)) {
                            visited[X][Y][step] = true;
                            D[X][Y][step] = D[cur.first][cur.second][step] + 1;
                            Q.push({X, Y});
                        }
                        continue;
                    }
                    if (grid[X][Y] == 1 && step >= 1) {
                        if (visited[cur.first][cur.second][step - 1] && (!visited[X][Y][step] || D[X][Y][step] > D[cur.first][cur.second][step - 1] + 1)) {
                            visited[X][Y][step] = true;
                            D[X][Y][step] = D[cur.first][cur.second][step - 1] + 1;
                            Q.push({X, Y});
                        }
                        continue;
                    }
                }
            }
        }
        for (int step = 1; step <= k; step++)
            if (visited[M - 1][N - 1][step])
                result = min(result, D[M - 1][N - 1][step]);
        return result == INT_MAX ? -1 : result;
    }
};

int main(void) {
    Solution s;
}