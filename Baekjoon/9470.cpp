#include <bits/stdc++.h>
using namespace std;

void task() {
    int K, M, P, x, y; cin >> K >> M >> P;
    vector<int> edge[M + 1] = {};
    vector<int> indegree (M + 1, 0);
    for (int i = 0; i < P; i++) {
        cin >> x >> y;
        edge[x].push_back(y);
        indegree[y]++;
    }
    vector<int> score (M + 1, 0);
    map<int, int> Map[M + 1] = {};
    int result = 1;
    queue<int> Q;
    for (int i = 1; i <= M; i++)
        if (!indegree[i]) {
            score[i] = 1;
            Q.push(i);
        }
    while (!Q.empty()) {
        int current = Q.front(); Q.pop();
        for (auto it : edge[current]) {
            indegree[it]--;
            Map[it][score[current]]++;
            if (!indegree[it]) {
                auto k = *Map[it].rbegin();
                score[it] = k.second == 1 ? k.first : k.first + 1; 
                result = max(result, score[it]);
                Q.push(it);
            }
        }
    }
    cout << K << ' ' << result << '\n';
}

int main(void) {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while (T--)
        task();
}
