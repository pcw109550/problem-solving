#include <bits/stdc++.h>
using namespace std;
#define INF 100000000
int V, E, P;
vector<pair<int, int> > edge[5001]; // {weight, vertex}

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
    int a, b, weight; cin >> V >> E >> P;
    for (int i = 0; i < E; i++) {
        cin >> a >> b >> weight;
        edge[a].push_back({weight, b});
        edge[b].push_back({weight, a});
    }
    int d1 = dijkstra(1, P);
    int d2 = dijkstra(P, V);
    int d  = dijkstra(1, V);
    cout << (d1 + d2 == d ? "SAVE HIM\n" : "GOOD BYE\n");   
}