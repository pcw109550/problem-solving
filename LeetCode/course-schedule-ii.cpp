// 210. Course Schedule II
#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>

class Solution {
    public:
        std::vector<int> findOrder(int numCourses, std::vector<std::vector<int>>& prerequisites) {
            // O(V + E) Topological Sort
            std::vector<std::vector<int> > adj (numCourses, std::vector<int> ());
            std::vector<int> indegree (numCourses, 0);
            std::vector<int> result;
            for (auto prerequisite : prerequisites) {
                adj[prerequisite[0]].push_back(prerequisite[1]);
                indegree[prerequisite[1]]++;
            }
            std::queue<int> Q;
            for (int i = 0; i < numCourses; i++)
                if (!indegree[i]) {
                    Q.push(i);
                    result.push_back(i);
                }
            while (!Q.empty()) {
                int cur = Q.front(); Q.pop();
                for (int v : adj[cur]) {
                    indegree[v]--;
                    if (!indegree[v]) {
                        Q.push(v);
                        result.push_back(v);
                    }
                }
            }
            for (int i = 0; i < numCourses; i++)
                if (indegree[i])
                    return std::vector<int> ();
            std::reverse(result.begin(), result.end());
            return result;
        }
};

int main(void) {
    Solution s;
}