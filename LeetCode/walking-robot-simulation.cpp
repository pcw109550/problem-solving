// 874. Walking Robot Simulation
#include <algorithm>
#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
using namespace std;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};


class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        // O(N + M)
        int result = 0;
        int N = commands.size();
        unordered_map<int, unordered_set<int> > M;
        for (auto obstacle : obstacles)
            M[obstacle[0]].insert(obstacle[1]);
        int x = 0, y = 0;
        int dir = 0;
        for (int i = 0; i < N; i++) {
            int nx = x, ny = y;
            if (commands[i] == -1)
                dir = (dir + 1) % 4;
            else if (commands[i] == -2)
                dir = (dir - 1 + 4) % 4;
            else {
                for (int k = 1; k <= commands[i]; k++) {
                    nx += dx[dir]; ny += dy[dir];
                    if (!M.count(nx) || !M[nx].count(ny)) {
                        x = nx;
                        y = ny;
                    } else
                        break;
                }
            }
            result = max(result, x * x + y * y);
        }
        return result;
    }
};

int main(void) {
    Solution s;
}