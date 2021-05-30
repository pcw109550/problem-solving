// 207. Course Schedule
#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>

class Solution {
    std::vector<std::vector<int> > adj;
    std::vector<bool> visited;
    bool result;
    std::unordered_set<int> S;
    public:
        bool canFinish(int numCourses, std::vector<std::vector<int> >& prerequisites) {
            // O(N) DFS
            adj.resize(numCourses, std::vector<int> ());
            visited.resize(numCourses, false);
            result = true;
            for (auto prerequisite : prerequisites)
                adj[prerequisite[0]].push_back(prerequisite[1]);
            for (int i = 0; i < numCourses; i++)
                if (!visited[i]) {
                    S.insert(i);
                    traversal(i);
                    S.erase(i);
                }
            return result;
        }
    
        void traversal(int i) {
            if (!result)
                return;
            visited[i] = true;
            for (int v : adj[i]) {
                if (S.count(v)) {
                    // i -> v is backedge
                    result = false;
                    return;
                }
                if (!visited[v]) {
                    S.insert(v);
                    traversal(v);
                    S.erase(v);
                }
            }
        }
};

class Solution2 {
    public:
        bool canFinish(int numCourses, std::vector<std::vector<int> >& prerequisites) {
            // O(V + E) Topological Sort
            std::vector<std::vector<int> > adj (numCourses, std::vector<int> ());
            std::vector<int> indegree (numCourses, 0);
            for (auto prerequisite : prerequisites) {
                adj[prerequisite[0]].push_back(prerequisite[1]);
                indegree[prerequisite[1]]++;
            }
            std::queue<int> Q;
            for (int i = 0; i < numCourses; i++)
                if (!indegree[i])
                    Q.push(i);
            while (!Q.empty()) {
                int cur = Q.front(); Q.pop();
                for (int v : adj[cur]) {
                    indegree[v]--;
                    if (!indegree[v])
                        Q.push(v);
                }
            }
            for (int i = 0; i < numCourses; i++)
                if (indegree[i])
                    return false;
            return true;
        }
};

int main(void) {
    Solution s;
}