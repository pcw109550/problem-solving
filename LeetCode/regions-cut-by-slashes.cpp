// 959. Regions Cut By Slashes
#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

class Solution {
public:
    int regionsBySlashes(vector<string>& grid) {
        // O(N ** 2)
        int N = grid.size();
        int result;
        vector<vector<vector<int> > > visited(N, vector<vector<int> > (N, vector<int>(4, 0)));
        int cnt = 0;
        queue<pair<pair<int, int>, int> > Q;
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++) {
                for (int k = 0; k < 4; k++) {
                    if (visited[i][j][k])
                        continue;
                    cnt++; visited[i][j][k] = cnt;
                    Q.push({{i, j}, k});
                    while (!Q.empty()) {
                        auto cur = Q.front(); Q.pop();
                        int x = cur.first.first;
                        int y = cur.first.second;
                        int z = cur.second;
                        if (grid[x][y] == ' ') {
                            if (!visited[x][y][(z + 1) % 4]) {
                                visited[x][y][(z + 1) % 4] = cnt;
                                Q.push({{x, y}, (z + 1) % 4});
                            }
                            if (!visited[x][y][(z + 3) % 4]) {
                                visited[x][y][(z + 3) % 4] = cnt;
                                Q.push({{x, y}, (z + 3) % 4});
                            }
                        } else if (grid[x][y] == '/') {
                            if ((z == 0 || z == 2) && !visited[x][y][(z + 3) % 4]) {
                                visited[x][y][(z + 3) % 4] = cnt;
                                Q.push({{x, y}, (z + 3) % 4});
                            } else if ((z == 1 || z == 3) && !visited[x][y][(z + 1) % 4]) {
                                visited[x][y][(z + 1) % 4] = cnt;
                                Q.push({{x, y}, (z + 1) % 4});
                            }
                        } else if (grid[x][y] == '\\') {
                            if ((z == 0 || z == 2) && !visited[x][y][(z + 1) % 4]) {
                                visited[x][y][(z + 1) % 4] = cnt;
                                Q.push({{x, y}, (z + 1) % 4});
                            } else if ((z == 1 || z == 3) && !visited[x][y][(z + 3) % 4]) {
                                visited[x][y][(z + 3) % 4] = cnt;
                                Q.push({{x, y}, (z + 3) % 4});
                            }
                        }
                        int X = x + dx[z], Y = y + dy[z];
                        if (X < 0 || Y < 0 || X >= N || Y >= N || visited[X][Y][(z + 2) % 4])
                            continue;
                        visited[X][Y][(z + 2) % 4] = cnt;
                        Q.push({{X, Y}, (z + 2) % 4});
                    }
                }
            }
        result = cnt;
        return result;
    }
};

int main(void) {
    Solution s;
}
