#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int N, M, x, y; cin >> N >> M; vector<int> graph[N + 1] = {};
    int distance[N + 1] = {};
    for (int i = 0; i < M; i++) {
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    queue<int> Q; vector<bool> visited(N + 1, false);
    Q.push(1); visited[1] = true;
    while (!Q.empty()) {
        int current = Q.front(); Q.pop();
        for (auto it = graph[current].begin(); it != graph[current].end(); it++) {
            if (!visited[*it]) {
                visited[*it] = true; distance[*it] = distance[current] + 1;
                Q.push(*it);
            }
        }
    }
    int Max = *max_element(distance, distance + N + 1);
    int cnt = 0, target; bool found = false;
    for (int i = 1; i <= N; i++) {
        if (distance[i] == Max && visited[i]) {
            if (!found) { found = true; target = i; }
            cnt++;
        }
    }
    cout << target << ' ' << distance[target] << ' ' << cnt;
}