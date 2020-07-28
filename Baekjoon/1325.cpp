#include<bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int N, M;
    cin >> N >> M;
    vector<int> edge[N + 1] = {};
    for (int i = 0; i < M; i++) {
        int x, y;
        cin >> x >> y;
        edge[y].push_back(x);
    }
    vector<int> weight[N + 1] = {};
    int Max = -1;
    for (int start = 1; start <= N; start++) {
        bool visited[N + 1] = {};
        queue<int> Q;
        visited[start] = true;
        Q.push(start);
        int cur_weight = 1;
        while (!Q.empty()) {
            int current = Q.front(); Q.pop();
            for (auto it : edge[current]) {
                if (visited[it])
                    continue;
                visited[it] = true;
                cur_weight++;
                Q.push(it);
            }
        }
        Max = max(cur_weight, Max);
        weight[cur_weight].push_back(start);
    }
    for (auto it : weight[Max])
        cout << it << ' ';
}   