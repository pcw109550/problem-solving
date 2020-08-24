// 785. Is Graph Bipartite?
#include <iostream>
#include <queue>
#include <vector>

class Solution {
    enum State {E, A, B};
    public:
        bool isBipartite(std::vector<std::vector<int> >& graph) {
            // O(N)
            int N = graph.size();
            if (N == 0)
                return true;
            std::vector<State> color(N, E);
            std::queue<int> Q;
            for (int i = 0; i < N; i++) {
                if (color[i] != E)
                    continue;
                color[i] = A;
                Q.push(i);
                while (!Q.empty()) {
                    int idx = Q.front(); Q.pop();
                    for (auto it : graph[idx]) {
                        if (color[it] == E) {
                            color[it] = (color[idx] == A ? B : A);
                            Q.push(it);
                            continue;
                        }
                        if (color[it] == color[idx])
                            return false;
                    }
                }
            }
            return true;
        }
};

int main(void) {
    Solution s;
    std::vector<std::vector<int> > graph {{1, 3}, {0, 2}, {1, 3}, {0, 2}};
    std::cout << s.isBipartite(graph);
}