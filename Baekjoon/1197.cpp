#include <bits/stdc++.h>
using namespace std;
#define EDGENUM 100000

using ti3 = tuple<int, int, int>;
vector<pair<int, int> > Graph[EDGENUM + 1];
bool visited[EDGENUM + 1];

int main(void) {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int V, E, start, weight, end, result = 0, acquired = 0; cin >> V >> E;
    for (int i = 0; i < E; i++) {
        cin >> start >> end >> weight;
        Graph[start].push_back({weight, end});
        Graph[end].push_back({weight, start});
    }
    priority_queue<ti3, vector<ti3>, greater<ti3> > PQ;
    // MST: Prim's algorithm O(E * log(E))
    // Start at node 1
    int startnode = 1; visited[startnode] = true;
    for (auto it : Graph[startnode]) {
        PQ.push({it.first, startnode, it.second});
    }
    while (true) {
        int weight, v1, v2;
        tie(weight, v1, v2) = PQ.top(); PQ.pop();
        if (visited[v2]) { continue; } visited[v2] = true;
        result += weight;
        if (++acquired == V - 1) { break; }
        for (auto it : Graph[v2]) {
            if (!visited[it.second]) {
                PQ.push({it.first, v2, it.second});
            }
        } 
    }
    cout << result;
}