// 1905. Count Sub Islands
#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};


class Solution {
    public:
        int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
            // O(M * N)
            int result = 0;
            int M = grid1.size();
            int N = grid1[0].size();
            vector<vector<bool> > visited (M, vector<bool> (N, false));
            for (int i = 0; i < M; i++)
                for (int j = 0; j < N; j++) {
                    if (visited[i][j])
                        continue;
                    if (!grid2[i][j])
                        continue;
                    queue<pair<int, int> > Q;
                    Q.push({i, j});
                    visited[i][j] = true;
                    bool track = true;
                    while (!Q.empty()) {
                        auto cur = Q.front(); Q.pop();
                        if (!grid1[cur.first][cur.second])
                            track = false;
                        for (int dir = 0; dir < 4; dir++) {
                            int X = cur.first + dx[dir];
                            int Y = cur.second + dy[dir];
                            if (X < 0 || Y < 0 || X >= M || Y >= N)
                                continue;
                            if (!visited[X][Y] && grid2[X][Y]) {
                                visited[X][Y] = true;
                                Q.push({X, Y});
                            }
                        }
                    }
                    if (track)
                        result++;
                }
            return result;
        }
};

int main(void) {
    Solution s;
}