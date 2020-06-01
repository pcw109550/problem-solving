#include <bits/stdc++.h>
using namespace std;

inline void task() {
    int N, M, a, b; cin >> N >> M; vector<int> path[N + 1] = {};
    for (int i = 0; i < M; i++) {
        cin >> a >> b;
        path[a].push_back(b);
        path[b].push_back(a);
    }
    bool visited[N + 1] = {}; int num[N + 1] = {};
    queue<int> Q; visited[1] = true; Q.push(1);
    int result = 0;
    while (!Q.empty()) {
        int current = Q.front(); Q.pop();
        for (auto it : path[current]) {
            if (!visited[it]) {
                result++;
                visited[it] = true;
                num[it] = num[current] + 1;
                Q.push(it);
            }
        }
    }
    cout << result << '\n';
}

int main(void) {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int T; cin >> T;
    while (T--) { task(); }
}