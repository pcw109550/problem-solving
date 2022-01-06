// 1466. Reorder Routes to Make All Paths Lead to the City Zero
#include <iostream>
#include <vector>
#include <utility>
#include <queue>
using namespace std;

class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        // O(N)
        int result = 0;
        int N = connections.size() + 1;
        vector<vector<pair<int, bool> > > neighbors (N);
        for (int i = 0; i < N - 1; i++) {
            int a = connections[i][0];
            int b = connections[i][1];
            neighbors[a].push_back({b, true});
            neighbors[b].push_back({a, false});
        }
        queue<int> Q;
        vector<bool> visited(N, false);
        visited[0] = true;
        Q.push(0);
        while (!Q.empty()) {
            int cur = Q.front(); Q.pop();
            for (auto neighbor : neighbors[cur]) {
                int next = neighbor.first;
                int dir = neighbor.second;
                if (visited[next])
                    continue;
                if (dir)
                    result++;
                visited[next] = true;
                Q.push(next);
            }
        }
        return result;
    }
};

int main(void) {
    Solution s;
}