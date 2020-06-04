#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int N, temp, root; cin >> N; vector<int> edge[N] = {};
    for (int i = 0; i < N; i++) {
        cin >> temp;
        if (temp == -1) { root = i; }
        else {
            edge[temp].push_back(i);
        }
    }
    bool visited[N] = {};
    int result = 0;
    cin >> temp;
    if (temp == root) {
        cout << 0; return 0;
    }
    visited[temp] = true;
    queue<int> Q; Q.push(root); visited[root] = true;
    while (!Q.empty()) {
        int current = Q.front(); Q.pop();
        if (edge[current].empty()) {
            result++;
        } else if (edge[current].size() == 1 && *edge[current].begin() == temp) {
            result++;
        } else {
            for (auto it : edge[current]) {
                if (!visited[it]) {
                    visited[it] = true;
                    Q.push(it);
                }
            }
        }
    }
    cout << result;
}