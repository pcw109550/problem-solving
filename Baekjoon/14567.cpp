#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int N, M, a, b; cin >> N >> M;
    vector<vector<int> > edge (N + 1, vector<int> ());   
    vector<int> indegree (N + 1, 0);
    for (int i = 0; i < M; i++) {
        cin >> a >> b;
        edge[a].push_back(b);
        indegree[b]++;
    }
    queue<pair<int, int> > Q;
    vector<int> result (N + 1, 1);
    for (int i = 1; i <= N; i++) {
        if (!indegree[i])
            Q.push({i, 1});
    }
    while (!Q.empty()) {
        auto current = Q.front(); Q.pop();
        int cur = current.first;
        int trace = current.second;
        result[cur] = max(result[cur], trace);
        for (auto n : edge[cur]) {
            indegree[n]--;
            if (!indegree[n])
                Q.push({n, trace + 1});
        }
    }
    for (int i = 1; i <= N; i++)
        cout << result[i] << ' ';
}