#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int N, temp; cin >> N;
    vector<int> weights (N + 1, 0);
    vector<int> results (N + 1, 0);
    vector<int> indegree (N + 1, 0);
    vector<int> edge[N + 1] = {};
    for (int i = 1; i <= N; i++) {
        cin >> weights[i] >> indegree[i];
        for (int j = 0; j < indegree[i]; j++) {
            cin >> temp;
            edge[temp].push_back(i);
        }
    }
    queue<pair<int, int> > Q;
    for (int i = 1; i <= N; i++) {
        if (!indegree[i]) {
            Q.push({i, weights[i]});
            results[i] = weights[i];
        }
    }
    while (!Q.empty()) {
        auto current = Q.front(); Q.pop();
        int idx = current.first;
        int weight = current.second;
        for (auto it : edge[idx]) {
            indegree[it]--;
            results[it] = max(results[it], weight + weights[it]);
            if (!indegree[it])
                Q.push({it, results[it]});
        }
    }
    int result = 0;
    for (int i = 1; i <= N; i++)
        result = max(result, results[i]);
    cout << result;
}