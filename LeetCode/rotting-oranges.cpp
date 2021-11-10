// 994. Rotting Oranges
#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        // O(M * N)
        int result = 0;
        int M = grid.size(), N = grid[0].size();
        vector<vector<int> > cnts (M, vector<int>(N, false));
        queue<pair<int, int> > Q;
        for (int i = 0; i < M; i++)
            for (int j = 0; j < N; j++)
                if (grid[i][j] == 2) {
                    Q.push({i, j});
                    cnts[i][j] = 1;
                }
        while (!Q.empty()) {
            auto cur = Q.front(); Q.pop();
            for (int dir = 0; dir < 4; dir++) {
                int X = cur.first + dx[dir];
                int Y = cur.second + dy[dir];
                if (X < 0 || Y < 0 || X >= M || Y >= N)
                    continue;
                if (grid[X][Y] == 0)
                    continue;
                if (cnts[X][Y] == 0 && grid[X][Y] == 1) {
                    grid[X][Y] = 2;
                    cnts[X][Y] = cnts[cur.first][cur.second] + 1;
                    Q.push({X, Y});
                }
            }
        }
        for (int i = 0; i < M; i++)
            for (int j = 0; j < N; j++)
                if (grid[i][j] >= 1) {
                    if (cnts[i][j] == 0)
                        return -1;
                    result = max(result, cnts[i][j] - 1);
                }
        return result;
    }
};

int main(void) {
    Solution s;
}