// 1391. Check if There is a Valid Path in a Grid
#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int paths[7] = {
    0b0000,
    0b0101,
    0b1010,
    0b0011,
    0b0110,
    0b1001,
    0b1100
};

class Solution {
public:
    bool hasValidPath(vector<vector<int>>& grid) {
        // O(M * N)
        int M = grid.size(), N = grid[0].size();
        vector<vector<int> > D(M, vector<int>(N, -1));
        queue<pair<int, int> > Q; Q.push({0, 0}); D[0][0] = 0;
        while (!Q.empty()) {
            auto cur = Q.front(); Q.pop();
            if (cur.first == M - 1 && cur.second == N - 1)
                return true;
            for (int dir = 0; dir < 4; dir++) {
                int X = cur.first + dx[dir];
                int Y = cur.second + dy[dir];
                if (X < 0 || Y < 0 || X >= M || Y >= N)
                    continue;
                if (D[X][Y] != -1)
                    continue;
                if (connected(grid[cur.first][cur.second], grid[X][Y], dir)) {
                    D[X][Y] = D[cur.first][cur.second] + 1;
                    Q.push({X, Y});
                }
            }
        }
        return false;
    }
    
    inline bool connected(int cur, int target, int dir) {
        int curval = paths[cur];
        int tarval = paths[target];
        if (dir == 0)
            return (curval & 0b0010) && (tarval & 0b1000);
        else if (dir == 1)
            return (curval & 0b0100) && (tarval & 0b0001);
        else if (dir == 2)
            return (curval & 0b1000) && (tarval & 0b0010);
        else if (dir == 3)
            return (curval & 0b0001) && (tarval & 0b0100);
        return false;
    }
};

int main(void) {
    Solution s;
}