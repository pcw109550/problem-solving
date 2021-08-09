// 827. Making A Large Island
#include <algorithm>
#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <set>
using namespace std;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        // O(M * N)
        int result = 0;
        int M = grid.size();
        int N = grid[0].size();
        unordered_map<int, int> S;
        S[0] = 0;
        vector<vector<bool> > visited (M, vector<bool>(N, false));
        int idx = 1;
        for (int i = 0; i < M; i++)
            for (int j = 0; j < N; j++) {
                if (visited[i][j])
                    continue;
                visited[i][j] = true;
                if (grid[i][j] == 0)
                    continue;
                queue<pair<int, int> > Q;
                grid[i][j] = idx;
                int size = 1;
                Q.push({i, j});
                while (!Q.empty()) {
                    auto cur = Q.front(); Q.pop();
                    for (int dir = 0; dir < 4; dir++) {
                        int X = cur.first + dx[dir];
                        int Y = cur.second + dy[dir];
                        if (X < 0 || Y < 0 || X >= M || Y >= N)
                            continue;
                        if (!visited[X][Y] && grid[X][Y] > 0) {
                            visited[X][Y] = true;
                            grid[X][Y] = idx;
                            size++;
                            Q.push({X, Y});
                        }
                    }
                }
                S[idx] = size;
                result = max(result, size);
                idx++;
            }
        for (int i = 0; i < M; i++)
            for (int j = 0; j < N; j++)
                if (grid[i][j] == 0) {
                    unordered_set<int> temp;
                    for (int dir = 0; dir < 4; dir++) {
                        int X = i + dx[dir];
                        int Y = j + dy[dir];
                        if (X < 0 || Y < 0 || X >= M || Y >= N)
                            continue;
                        if (grid[X][Y] != 0)
                            temp.insert(grid[X][Y]);
                    }
                    multiset<int> sizes;
                    for (auto it : temp)
                        sizes.insert(S[it]);
                    auto it = sizes.rbegin();
                    int temp_result = 1;
                    for (auto it : sizes)
                        temp_result += it;
                    result = max(result, temp_result);
                }
        return result;
    }
};

int main(void) {
    Solution s;
}