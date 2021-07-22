// 463. Island Perimeter
#include <iostream>
#include <vector>
using namespace std;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        // O(M * N)
        int result = 0;
        int M = grid.size();
        int N = grid[0].size();
        for (int i = 0; i < M; i++)
            for (int j = 0; j < N; j++)
                if (grid[i][j]) {
                    for (int dir = 0; dir < 4; dir++) {
                        int X = i + dx[dir];
                        int Y = j + dy[dir];
                        if (X < 0 || Y < 0 || X >= M || Y >= N)
                            result++;
                        else if (grid[X][Y] == 0)
                            result++;
                    }
                }
        return result;
    }
};

int main(void) {
    Solution s;
}