// 797. All Paths From Source to Target
#include <iostream>
#include <vector>
#include <queue>

class Solution {
    public:
        std::vector<std::vector<int> > allPathsSourceTarget(std::vector<std:: vector<int> >& graph) {
            // O(N ** 3)
            int N = graph.size();
            std::vector<int> indegree(N, 0);
            for (int i = 0; i < N; i++)
                for (auto it : graph[i])
                    indegree[it]++;
            std::queue<int> Q;
            std::vector<std::vector<std::vector<int> > > path (N);
            std::vector<std::vector<int> > result;
            for (int i = 0; i < N; i++)
                if (indegree[i] == 0) {
                    Q.push(i);
                    path[i].push_back(std::vector<int>(1, i));
                }
            while (!Q.empty()) {
                int cur = Q.front(); Q.pop();
                for (auto it : graph[cur]) {
                    indegree[it]--;
                    for (auto prev_path : path[cur]) {
                        auto next_path = prev_path;
                        next_path.push_back(it);
                        path[it].push_back(next_path);
                    }        
                    if (indegree[it] == 0)
                        Q.push(it);                    
                }
            }
            for (auto it : path[N - 1])
                if (it.front() == 0)
                    result.push_back(it);
            return result;
        }
};

int main(void) {
    Solution s;
}