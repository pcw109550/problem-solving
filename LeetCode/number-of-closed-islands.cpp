#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
        // O(M * N)
        int result = 0;
        int M = grid.size(), N = grid[0].size();
        queue<pair<int, int> > Q;
        vector<vector<bool> > visited(M, vector<bool>(N, false));
        for (int i = 0; i < M; i++) 
            for (int j = 0; j < N; j++) {
                if (visited[i][j] || grid[i][j] == 1)
                    continue;
                visited[i][j] = true;
                Q.push({i, j}); 
                bool out = false;
                while (!Q.empty()) {
                    auto cur = Q.front(); Q.pop();
                    for (int dir = 0; dir < 4; dir++) {
                        int X = cur.first + dx[dir];
                        int Y = cur.second + dy[dir];
                        if (X < 0 || Y < 0 || X >= M || Y >= N) {
                            out = true;
                            continue;
                        }
                        if (grid[X][Y] || visited[X][Y])
                            continue;
                        visited[X][Y] = true;
                        Q.push({X, Y});
                    }
                }
                if (!out)
                    result++;
            }
        return result;
    }
};