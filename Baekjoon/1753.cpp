#include <bits/stdc++.h>
using namespace std;
#define INF 3000000

int main(void) {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int V, E, K, x, y, weight; cin >> V >> E >> K;
    vector<pair<int, int> > edge[V + 1];
    for (int i = 0; i < E; i++) {
        cin >> x >> y >> weight;
        edge[x].push_back({weight, y});
    }
    // Dijkstra O(E * log(E))
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > PQ;
    int D[V + 1] = {}; fill(D, D + V + 1, INF);
    D[K] = 0; PQ.push({0, K}); // {distance, vertex}
    while (!PQ.empty()) {
        auto top = PQ.top(); PQ.pop();
        int distance = top.first, vertex = top.second;
        if (D[vertex] == distance) {
            for (auto it : edge[vertex]) {
                int cost = it.first, nvertex = it.second;
                int updated = distance + cost;
                if (D[nvertex] > updated) {
                    D[nvertex] = updated;
                    PQ.push({D[nvertex], nvertex});    
                }
            }
        }
    }
    for (int i = 1; i <= V; i++) {
        if (D[i] == INF) { cout << "INF\n"; }
        else             { cout << D[i] << '\n'; }
    }
}