#include <bits/stdc++.h>
using namespace std;
#define INF 1e8

inline void task(int V, int E) {
    int start, end, a, b, weight; cin >> start >> end;
    vector<pair<int, int> > edge[V] = {}; // {weight, vertex}
    for (int i = 0; i < E; i++) {
        cin >> a >> b >> weight;
        edge[a].push_back({weight, b});
    }
    vector<int> path[V] = {};
    int D[V]; fill(D, D + V, INF);
    // Dijkstra O(E * log(E))
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > PQ;
    D[start] = 0; PQ.push({0, start});
    while (!PQ.empty()) {
        auto current = PQ.top(); PQ.pop();
        int distance = current.first;
        int vertex = current.second;
        if (D[vertex] == distance) {
            for (auto it : edge[vertex]) {
                int weight = it.first;
                int nvertex = it.second;
                if (D[nvertex] >= distance + weight) {
                    if (D[nvertex] > distance + weight) {
                        path[nvertex].clear();
                    }
                    path[nvertex].push_back(vertex);
                    D[nvertex] = distance + weight;
                    PQ.push({D[nvertex], nvertex});
                }
            }
        }
    }
    // Remove shortest paths
    queue<int> Q; Q.push(end); bool visited[V] = {}; visited[end] = true;
    while (!Q.empty()) {
        int cur = Q.front(); Q.pop();
        for (auto it : path[cur]) {
            if (!visited[it]) { Q.push(it); }
            edge[it].erase(remove_if(edge[it].begin(), edge[it].end(),
                    [cur](pair<int, int> x){ return x.second == cur; }), edge[it].end());
        }
    }
    // Run dijkstra again O(E * log(E))
    int D2[V]; fill(D2, D2 + V, INF);
    D2[start] = 0; PQ.push({0, start});
    while (!PQ.empty()) {
        auto current = PQ.top(); PQ.pop();
        int distance = current.first;
        int vertex = current.second;
        if (D2[vertex] == distance) {
            for (auto it : edge[vertex]) {
                int weight = it.first;
                int nvertex = it.second;
                if (D2[nvertex] >= distance + weight) {
                    if (D2[nvertex] > distance + weight) {
                        path[nvertex].clear();
                    }
                    path[nvertex].push_back(vertex);
                    D2[nvertex] = distance + weight;
                    PQ.push({D2[nvertex], nvertex});
                }
            }
        }
    }
    cout << (D2[end] == INF ? -1 : D2[end]) << '\n';
}

int main(void) {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int V, E;
    while (true) {
        cin >> V >> E;
        if (V == 0 && E == 0) { return 0; }
        task(V, E);
    }
}