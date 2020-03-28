#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);
    int K, V, E, x, y; cin >> K;
    // Use the fact of size of E is limited to 200000
    for (int k = 0; k < K; k++) {
        cin >> V >> E; vector<int> Map[V] = {};
        for (int i = 0; i < E; i++) {
            cin >> x >> y; x--; y--; Map[x].push_back(y); Map[y].push_back(x);
        }
        vector<pair<bool, bool>> visited(V, {false, false}); bool result = true;
        for (int j = 0; j < V; j++) {
            if (!result) { break; }
            if (!visited[j].first) {
                queue<int> Q; visited[j] = {true, false}; Q.push(j);
                while (!Q.empty() && result) {
                    int current = Q.front(); Q.pop();
                    for (int i = 0; i < Map[current].size(); i++) {
                        int adj = Map[current][i];
                        if (adj == current) { continue; }
                        if (!visited[adj].first) {
                            visited[adj] = {true, !visited[current].second};
                            Q.push(adj);
                        } else {
                            if (visited[adj].second == visited[current].second) {
                                result = false; break;
                            }
                        }
                    }
                }
                if (!result) { break; }
            }
        }
        cout << (result ? "YES\n" : "NO\n");
    }
}