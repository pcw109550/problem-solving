#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int N, M, x, y; cin >> N >> M;
    vector<int> edge[N + 1] = {};
    int indegree[N + 1] = {};
    // Topological Sort O(V + E)
    for (int i = 0; i < M; i++) {
        cin >> x >> y;
        edge[x].push_back(y);
        indegree[y]++;
    }
    queue<int> Q; vector<int> result;
    for (int i = 1; i <= N; i++) {
        if (!indegree[i]) { Q.push(i); }
    }
    while (!Q.empty()) {
        int current = Q.front(); Q.pop();
        result.push_back(current);
        for (auto it : edge[current]) {
            indegree[it]--;
            if (!indegree[it]) { Q.push(it); }
        }
    }
    for (auto it : result) {
        cout << it << ' ';
    }
}