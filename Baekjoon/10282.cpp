#include <bits/stdc++.h>
using namespace std;
#define INF 1e7

inline void task() {
    int V, E, start, a, b, weight; cin >> V >> E >> start;
    vector<pair<int, int> > edge[V + 1] = {}; // {weight, vertex}
    for (int i = 0; i < E; i++) {
        cin >> a >> b >> weight;
        edge[b].push_back({weight, a});
    }
    // Dijkstra O(E * log(E))
    int D[V + 1]; fill(D, D + V + 1, INF);
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > PQ;
    D[start] = 0; PQ.push({0, start}); // {distance, vertex}
    while (!PQ.empty()) {
        auto current = PQ.top(); PQ.pop();
        int distance = current.first;
        int vertex = current.second;
        if (D[vertex] == distance) {
            for (auto it : edge[vertex]) {
                int weight = it.first;
                int nvertex = it.second;
                if (D[nvertex] > distance + weight) {
                    D[nvertex] = distance + weight;
                    PQ.push({D[nvertex], nvertex});
                }
            }
        }
    }
    int cnt = 0, Max = -1; 
    for (int i = 1; i <= V; i++) {
        if (D[i] != INF) {
            cnt++;
            Max = max(D[i], Max);
        }
    }
    cout << cnt << ' ' << Max << '\n';
}

int main(void) {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while (T--) {
        task();
    }
} 