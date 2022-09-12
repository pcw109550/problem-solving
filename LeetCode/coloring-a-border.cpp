#include <iostream>
#include <vector>
#include <utility>
#include <queue>
using namespace std;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

class Solution {
public:
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) {
        // O(M * N)
        int M = grid.size(), N = grid[0].size();
        vector<vector<int> > result = grid;
        int color_start = grid[row][col];
        queue<pair<int, int> > Q;
        vector<vector<bool> > visited (M, vector<bool>(N, false));
        Q.push({row, col});
        while (!Q.empty()) {
            auto it = Q.front(); Q.pop();
            bool border = false;
            for (int dir = 0; dir < 4; dir++) {
                int X = it.first + dx[dir];
                int Y = it.second + dy[dir];
                if (X < 0 || Y < 0 || X >= M || Y >= N) {
                    border = true;
                    continue;
                }
                if (!visited[X][Y] && grid[X][Y] == color_start) {
                    visited[X][Y] = true;
                    Q.push({X, Y});
                } else if (grid[X][Y] != color_start)
                    border = true;
            }
            if (border)
                result[it.first][it.second] = color;
        }        
        return result;
    }
};