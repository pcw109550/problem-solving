#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int N, M, X, Y, K; cin >> N >> M;
    vector<int> edge[N + 1] = {};
    unordered_map<int, unordered_map<int, int> > cnt;
    vector<int> indegree (N + 1, 0);
    vector<int> preserve;
    for (int i = 0; i < M; i++) {
        cin >> X >> Y >> K;
        edge[Y].push_back(X);
        indegree[X]++;
        cnt[X][Y] = K;
    }
    vector<int> step;
    queue<int> Q;
    for (int i = 1; i <= N; i++) {
        if (!indegree[i])
            Q.push(i);
    }
    preserve = indegree;
    while (!Q.empty()) {
        int current = Q.front(); Q.pop();
        step.push_back(current);
        for (auto it : edge[current]) {
            indegree[it]--;
            if (!indegree[it])
                Q.push(it);
        }
    }
    unordered_map<int, unordered_map<int, int> > acc;
    for (auto it : step) {
        if (!preserve[it]) {
            acc[it][it] = 1;
            continue;
        }
        for (auto source : cnt[it]) {
            for (auto parts : acc[source.first]) {
                acc[it][parts.first] += parts.second * source.second;
            }
        }
    }
    map<int, int> result;
    for (auto it : acc[N])
        result.insert({it.first, it.second});
    for (auto it : result)
        cout << it.first << ' ' << it.second << endl;
}