#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int N, M, x, y, num; cin >> N >> M;
    vector<int> edge[N + 1] = {};
    int indegree[N + 1] = {};
    // Topological Sort O(V + E)
    for (int i = 0; i < M; i++) {
        cin >> num >> x;
        for (int j = 1; j < num; j++) {
            cin >> y;
            edge[x].push_back(y);
            indegree[y]++;
            x = y;
        }
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
    if (result.size() != N) {
        cout << 0;
        return 0;
    }
    for (auto it : result) {
        cout << it << '\n';
    }
}