// 886. Possible Bipartition
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        // O(N)
        vector<int> visited (n + 1, 0);
        vector<vector<int> > neighbors (n + 1, vector<int>());
        for (auto it : dislikes) {
            int a = it[0], b = it[1];
            neighbors[a].push_back(b);
            neighbors[b].push_back(a);
        }
        for (int i = 1; i <= n; i++) {
            if (!visited[i]) {
                visited[i] = 1;
                queue<int> Q; Q.push(i);
                while (!Q.empty()) {
                    auto cur = Q.front(); Q.pop();
                    for (auto neighbor : neighbors[cur]) {
                        if (!visited[neighbor]) {
                            visited[neighbor] = 1 + (visited[cur] % 2);
                            Q.push(neighbor);
                        } else if (visited[cur] == visited[neighbor])
                            return false;
                    }
                }
            }
        }
        return true;    
    }
};

int main(void) {
    Solution s;
}
