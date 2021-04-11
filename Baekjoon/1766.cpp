#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    // O(E + V * log(V))
    int N, M, a, b; cin >> N >> M;
    vector<int> edge[N + 1] = {};
    vector<int> indegree (N + 1, 0);
    for (int i = 0; i < M; i++) {
        cin >> a >> b;
        edge[a].push_back(b);
        indegree[b]++;
    }
    priority_queue<int, vector<int>, greater<int> > PQ;
    for (int i = 1; i <= N; i++) {
        if (!indegree[i])
            PQ.push(i);
    }
    vector<int> result;
    while (!PQ.empty()) {
        int current = PQ.top(); PQ.pop();
        result.push_back(current);
        for (auto it : edge[current]) {
            indegree[it]--;
            if (!indegree[it])
                PQ.push(it);
        }
    }
    for (auto it : result)
        cout << it << ' ';
}