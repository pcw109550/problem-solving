#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int N, a; cin >> N;
    vector<int> weights (N + 1, 0);
    vector<int> indegree (N + 1, 0);
    vector<int> edge[N + 1] = {};
    for (int i = 1; i <= N; i++) {
        cin >> weights[i];
        while (true) {
            cin >> a;
            if (a == -1)
                break;
            edge[a].push_back(i);
            indegree[i]++;
        }
    }
    vector<int> result (N + 1, 0);
    queue<pair<int, int> > Q;
    for (int i = 1; i <= N; i++) {
        if (!indegree[i]) {
            Q.push({i, weights[i]});
            result[i] = weights[i];
        }
    }
    while (!Q.empty()) {
        auto current = Q.front(); Q.pop();
        int idx = current.first;
        int weight = current.second;
        for (auto it : edge[idx]) {
            result[it] = max(result[it], weight + weights[it]);
            indegree[it]--;
            if (!indegree[it])
                Q.push({it, result[it]});
        }
    }
    for (int i = 1; i <= N; i++)
        cout << result[i] << '\n';
}