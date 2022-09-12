#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

class Solution {
    int result, M, N;
public:
    int getMaximumGold(vector<vector<int>>& grid) {
        // O(M ** 2 * N ** 2)
        result = 0, M = grid.size(), N = grid[0].size();
        for (int i = 0; i < M; i++)
            for (int j = 0; j < N; j++) {
                if (grid[i][j] == 0)
                    continue;
                vector<vector<bool> > visited(M, vector<bool>(N, false));
                traversal(grid, visited, i, j, 0);
            }
        return result;
    }
    
    void traversal(vector<vector<int> >& grid, vector<vector<bool> > &visited, int x, int y, int acc) {
        visited[x][y] = true;
        acc += grid[x][y];
        result = max(result, acc);
        for (int dir = 0; dir < 4; dir++) {
            int X = x + dx[dir], Y = y + dy[dir];
            if (X < 0 || Y < 0 || X >= M || Y >= N)
                continue;
            if (visited[X][Y] || grid[X][Y] == 0)
                continue;
            visited[X][Y] = true;
            traversal(grid, visited, X, Y, acc);
            visited[X][Y] = false;
        }
    }
};