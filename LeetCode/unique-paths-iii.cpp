// 980. Unique Paths III
#include <iostream>
#include <vector>
using namespace std;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

class Solution {
    int result, M, N, sx, sy, space;
public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        // O(4 ** (M * N))
        M = grid.size(); N = grid[0].size();
        vector<vector<int> > state (M, vector<int>(N, 0));
        for (int i = 0; i < M; i++)
            for (int j = 0; j < N; j++) {
                if (grid[i][j] == 1) {
                    sx = i;
                    sy = j;
                    space++;
                } else if (grid[i][j] != -1)
                    space++;
            }
        state[sx][sy] = 1;
        backtrack(grid, state, sx, sy, 1);
        return result;
    }
    
    void backtrack(vector<vector<int>>& grid, vector<vector<int>>& state, int x, int y, int occ) {
        if (grid[x][y] == 2) {
            if (occ == space)
                result++;
            return;
        }
        for (int dir = 0; dir < 4; dir++) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if (nx < 0 || ny < 0 || nx >= M || ny >= N)
                continue;
            if (grid[nx][ny] == -1 || state[nx][ny] == 1)
                continue;
            state[nx][ny] = 1;
            backtrack(grid, state, nx, ny, occ + 1);
            state[nx][ny] = 0;
        }
    }
};

int main(void) {
    Solution s;
}