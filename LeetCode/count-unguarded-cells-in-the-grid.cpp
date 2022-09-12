#include <iostream>
#include <vector>
using namespace std;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        // O(M * N)
        int result = 0;
        vector<vector<int> > D(m, vector<int>(n, 0));
        for (auto wall : walls)
            D[wall[0]][wall[1]] = 4;
        for (auto guard : guards)
            D[guard[0]][guard[1]] = 8;
        for (auto guard : guards) {
            int X = guard[0], Y = guard[1];
            for (int dir = 0; dir < 4; dir++) {
                int dxx = dx[dir], dyy = dy[dir];
                int delta = 1;
                while (true) {
                    int nx = X + dxx * delta;
                    int ny = Y + dyy * delta;
                    if (nx < 0 || ny < 0 || nx >= m || ny >= n || D[nx][ny] >= 4)
                        break;
                    if ((D[nx][ny] & (1 << (dir % 2))) == (1 << (dir % 2))) 
                        break;
                    D[nx][ny] |= (1 << (dir % 2));
                    delta++;
                }
            }
        }
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (!D[i][j])
                    result++;
        return result;
    }
};