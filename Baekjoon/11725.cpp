#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int N, x, y; cin >> N; vector<int> Map[N] = {};
    int parent[N] = {};
    for (int i = 0; i < N - 1; i++) {
        cin >> x >> y; x--; y--;
        Map[x].push_back(y); Map[y].push_back(x); 
    }
    queue<int> Q; bool visited[N] = {};
    visited[0] = true; Q.push(0);
    while (!Q.empty()) {
        auto current = Q.front(); Q.pop();
        for (auto it = Map[current].begin(); it != Map[current].end(); it++) {
            if (!visited[*it]) {
                visited[*it] = true; parent[*it] = current; Q.push(*it);
            }
        }
    }
    for (int i = 1; i < N; i++) {
        cout << parent[i] + 1 << '\n';
    }
}