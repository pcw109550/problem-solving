// 685. Redundant Connection II
#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
using namespace std;

class Solution {
    public:
        vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
            // O(N ** 2)
            vector<int> result;
            int N = edges.size();
            vector<unordered_set<int> > neighbors (N + 1, unordered_set<int>());
            vector<int> Indegree (N + 1, 0);
            Indegree[0] = -1;
            for (int i = 0; i < N; i++) {
                Indegree[edges[i][1]]++;
                neighbors[edges[i][0]].insert(edges[i][1]);
            }
            for (int i = N - 1; i >= 0; i--) {
                auto indegree = Indegree;
                indegree[edges[i][1]]--;
                int start = 0;
                bool check = false;
                for (int j = 1; j <= N; j++) {
                    if (indegree[j] == 0) {
                        if (start != 0) {
                            check = true;
                            break;
                        }
                        start = j;
                    }
                }
                // if two roots exist, continue
                if (check || start == 0)
                    continue;
                queue<int> Q;
                Q.push(start);
                while (!Q.empty()) {
                    int cur = Q.front(); Q.pop();
                    for (auto neighbor : neighbors[cur]) {
                        if (cur == edges[i][0] && neighbor == edges[i][1])
                            continue;
                        indegree[neighbor]--;
                        if (indegree[neighbor] == 0)
                            Q.push(neighbor);
                    }
                }
                for (int j = 1; j <= N; j++)
                    if (indegree[j] != 0) {
                        check = true;
                        break;
                    }
                if (!check) {
                    result = edges[i];
                    break;
                }
            }
            return result;
        }
};

int main(void) {
    Solution s;
}