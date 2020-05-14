#include <bits/stdc++.h>
using namespace std;
#define INF 1e12

int main(void) {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int V, E, start, end, x, y, weight; cin >> V >> E;
    vector<pair<int, int> > edge[V + 1];
    for (int i = 0; i < E; i++) {
        cin >> x >> y >> weight;
        edge[x].push_back({weight, y});
    }
    cin >> start >> end;
    // Dijkstra O(E * log(E))
    priority_queue<pair<long long, int>, vector<pair<long long, int> >, greater<pair<long long, int> > > PQ;
    long long D[V + 1] = {}; fill(D, D + V + 1, INF);
    D[start] = 0; PQ.push({0, start}); // {distance, vertex}
    while (!PQ.empty()) {
        auto top = PQ.top(); PQ.pop();
        long long distance = top.first; int vertex = top.second;
        if (D[vertex] == distance) {
            for (auto it : edge[vertex]) {
                int cost = it.first, nvertex = it.second;
                long long updated = distance + (long long)cost;
                if (D[nvertex] > updated) {
                    D[nvertex] = updated;
                    PQ.push({D[nvertex], nvertex});    
                }
            }
        }
    }
    cout << D[end];
}