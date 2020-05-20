#include <bits/stdc++.h>
using namespace std;
#define INF 10000

int main(void) {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int V, E, a, b, weight; cin >> V >> E;
    vector<pair<int, int> > edge[V + 1] = {}; // {weight, vertex}
    for (int i = 0; i < E; i++) {
        cin >> a >> b >> weight;
        edge[a].push_back({weight, b});
        edge[b].push_back({weight, a});
    }
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > PQ;
    int D[V + 1] = {}; fill(D, D + V + 1, INF); int path[V + 1] = {};
    D[1] = 0; PQ.push({0, 1});
    while (!PQ.empty()) {
        auto current = PQ.top(); PQ.pop();
        int distance = current.first;
        int vertex = current.second;
        if (D[vertex] == distance) {
            for (auto it : edge[vertex]) {
                int weight = it.first;
                int nvertex = it.second;
                if (D[nvertex] > weight + distance) {
                    D[nvertex] = weight + distance;
                    path[nvertex] = vertex;
                    PQ.push({D[nvertex], nvertex});
                }
            }
        }
    }
    cout << V - 1 << '\n';
    for (int i = 2; i <= V; i++) {
        cout << i << ' ' << path[i] << '\n';
    }
}