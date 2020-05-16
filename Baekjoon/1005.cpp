#include <bits/stdc++.h>
using namespace std;

inline void task() {
    int N, M, x, y, target; cin >> N >> M;
    vector<int> edge[N + 1] = {};
    int weight[N + 1] = {};
    int distance[N + 1] = {};
    for (int i = 1; i <= N; i++) {
        cin >> weight[i];
    }
    int indegree[N + 1] = {};
    // Topological Sort O(V + E)
    for (int i = 0; i < M; i++) {
        cin >> x >> y;
        edge[x].push_back(y);
        indegree[y]++;
    }
    cin >> target;
    queue<int> Q; vector<int> result;
    for (int i = 1; i <= N; i++) {
        if (!indegree[i]) {
            Q.push(i);
            distance[i] = weight[i];
        }
    }
    while (!Q.empty()) {
        int current = Q.front(); Q.pop();
        result.push_back(current);
        for (auto it : edge[current]) {
            indegree[it]--;
            if (!indegree[it]) { Q.push(it); }
            if (distance[it] < distance[current] + weight[it]) {
                distance[it] = distance[current] + weight[it];
            }
        }
    }
    cout << distance[target] << '\n';
}

int main(void) {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while (T--) {
        task();
    }
}