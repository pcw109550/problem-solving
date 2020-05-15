#include <bits/stdc++.h>
using namespace std;
#define INF 1e10

int main(void) {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int V, E, start, end, a, b, weight; cin >> V >> E;
    vector<pair<int, int> > edge[V + 1]; // {weight, vertex}
    for (int i = 0; i < E; i++) {
        cin >> a >> b >> weight;
        edge[a].push_back({weight, b});
    }
    cin >> start >> end;
    // Dijkstra O(E * log(E))
    long long D[V + 1]; fill(D, D + V + 1, INF);
    int path[V + 1] = {};
    // {distance, vertex}
    priority_queue<pair<long long, int>, vector<pair<long long, int> >, greater<pair<long long, int> > > PQ;
    D[start] = 0; PQ.push({0, start});
    while (!PQ.empty()) {
        auto current = PQ.top(); PQ.pop();
        long long distance = current.first;
        int vertex = current.second;
        if (D[vertex] == distance) {
            for (auto it : edge[vertex]) {
                long long weight = it.first;
                int nvertex = it.second;
                if (D[nvertex] > distance + (long long)weight) {
                    D[nvertex] = distance + (long long)weight;
                    path[nvertex] = vertex;
                    PQ.push({D[nvertex], nvertex});
                }
            }
        }
    }
    cout << D[end] << '\n';
    int cur = end;
    vector<int> paths;
    while (cur != start) {
        paths.push_back(cur);
        cur = path[cur];
    }
    paths.push_back(start);
    cout << paths.size() << '\n';
    for (auto it = paths.rbegin(); it != paths.rend(); it++) {
        cout << *it << ' ';
    }
}