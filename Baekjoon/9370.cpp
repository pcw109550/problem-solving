#include <bits/stdc++.h>
using namespace std;
#define INF 10e8

inline void task() {
    int V, E, t, s, g, h; cin >> V >> E >> t >> s >> g >> h;
    int a, b, weight; int end[t] = {};
    vector<pair<int, int> > edge[V + 1] = {}; // {weight, vertex}
    for (int i = 0; i < E; i++) {
        cin >> a >> b >> weight;
        edge[a].push_back({weight, b});
        edge[b].push_back({weight, a});
    }
    for (int i = 0; i < t; i++) {
        cin >> end[i];
    }
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > PQ;
    // Dijkstra O(E * log(E))
    int D[V + 1]; fill(D, D + V + 1, INF); vector<int> path[V + 1] = {};
    D[s] = 0; PQ.push({0, s});
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
                        D[nvertex] = distance + weight;
                        PQ.push({D[nvertex], nvertex});
                    }
                    path[nvertex].push_back(vertex);
                }
            }
        }
    }
    vector<int> result;
    for (int i = 0; i < t; i++) {
        int e = end[i];
        if (D[e] == INF) { continue; }
        queue<int> Q; Q.push(e); bool found = false;
        bool visited[V + 1] = {}; visited[e] = true;
        while (!Q.empty()) {
            int current = Q.front(); Q.pop();
            for (auto it : path[current]) {
                if ((it == g && current == h) || (it == h && current == g)) {
                    result.push_back(end[i]);
                    found = true;
                    break;
                }
                if (!visited[it]) {
                    visited[it] = true;
                    Q.push(it);
                }
            }
            if (found) {
                 break;
            }
        }
    }
    sort(result.begin(), result.end());
    for (auto it : result) {
        cout << it << ' ';
    }
    cout << '\n';
}

int main(void) {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while (T--) {
        task();
    }
}