#include <bits/stdc++.h>
using namespace std;
#define INF 160000000
int V, E;
vector<pair<int, int> > edge[801]; // {weight, vertex}

int dijkstra(int start, int end) {
    int D[V + 1]; fill(D, D + V + 1, INF);
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
                if (D[nvertex] > distance + weight) {
                    D[nvertex] = distance + weight;
                    PQ.push({D[nvertex], nvertex});
                }
            }
        }
    }
    return D[end];
}

int main(void) {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int a, b, v1, v2, weight; cin >> V >> E;
    for (int i = 0; i < E; i++) {
        cin >> a >> b >> weight;
        edge[a].push_back({weight, b});
        edge[b].push_back({weight, a});
    }
    cin >> v1 >> v2;
    int t1 = dijkstra(1, v1);
    int t2 = dijkstra(1, v2);
    int d  = dijkstra(v1, v2);
    int t3 = dijkstra(v1, V);
    int t4 = dijkstra(v2, V);
    int result = d + min(t1 + t4, t2 + t3);
    cout << (result >= INF ? -1 : result);
}