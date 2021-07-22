// 1765. Map of Highest Peak
#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

class Solution {
    public:
        vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
            // O(M * N)
            int M = isWater.size();
            int N = isWater[0].size();
            vector<vector<int> > result (M, vector<int>(N, 0));
            vector<vector<bool> > visited (M, vector<bool>(N, false));
            queue<pair<int, int> > Q;
            for (int i = 0; i < M; i++)
                for (int j = 0; j < N; j++)
                    if (isWater[i][j] == 1) {
                        visited[i][j] = true;
                        Q.push({i, j});
                    }
            while (!Q.empty()) {
                auto cur = Q.front(); Q.pop();
                for (int dir = 0; dir < 4; dir++) {
                    int X = cur.first + dx[dir];
                    int Y = cur.second + dy[dir];
                    if (X < 0 || Y < 0 || X >= M || Y >= N)
                        continue;
                    if (!visited[X][Y]) {
                        visited[X][Y] = true;
                        Q.push({X, Y});
                        result[X][Y] = result[cur.first][cur.second] + 1;
                    }
                }
            }
            return result;
        }
};

int main(void) {
    Solution s;
}