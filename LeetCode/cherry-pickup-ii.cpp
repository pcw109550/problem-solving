// 1463. Cherry Pickup II
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        // O(M * N ** 2)
        int result = 0;
        int M = grid.size(), N = grid[0].size();
        vector<vector<vector<int> > > D(M, vector<vector<int> >(N, vector<int>(N, -1)));
        D[0][0][N - 1] = grid[0][0] + grid[0][N - 1];
        for (int i = 1; i < M; i++) {
            for (int j = 0; j < N; j++)
                for (int k = 0; k < N; k++) {
                    int prev_max = -1;
                    for (int x = -1; x <= 1; x++)
                        for (int y = -1; y <= 1; y++) {
                            int X = j + x, Y = k + y;
                            if (X < 0 || Y < 0 || X >= N || Y >= N)
                                continue;
                            prev_max = max(prev_max, D[i - 1][X][Y]);
                        }
                    if (prev_max == -1)
                        continue;
                    D[i][j][k] = prev_max;
                    D[i][j][k] += j == k ? grid[i][j] : grid[i][j] + grid[i][k];
                }
        }
        for (int j = 0; j < N; j++)
            for (int k = 0; k < N; k++)
                result = max(result, D[M - 1][j][k]);
        return result;
    }
};

int main(void) {
    Solution s;
}