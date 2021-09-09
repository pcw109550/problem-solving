// 882. Reachable Nodes In Subdivided Graph
#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int reachableNodes(vector<vector<int>>& edges, int maxMoves, int n) {
        // O(E * log(E))
        long long result = 0;
        vector<long long> dist(n, INT_MAX);
        dist[0] = 0;
        vector<vector<pair<int, long long> > > E (n, vector<pair<int, long long> > ());
        unordered_map<int, unordered_map<int, vector<int> > > M;
        for (auto edge : edges) {
            int a = edge[0], b = edge[1];
            long long weight = edge[2];
            E[a].push_back({b, weight});
            E[b].push_back({a, weight});
            M[min(a, b)][max(a, b)].push_back(weight);
        }
        // {dist, node}
        priority_queue<pair<long long, int>, vector<pair<long long, int> >, greater<pair<long long, int> > > PQ;
        PQ.push({dist[0], 0});
        while (!PQ.empty()) {
            auto cur = PQ.top(); PQ.pop();
            int v = cur.second, v_dist = cur.first;
            if (dist[v] != v_dist)
                continue;
            for (auto it : E[v]) {
                int w = it.first, weight = it.second;
                if (dist[w] > weight + v_dist + 1) {
                    dist[w] = weight + v_dist + 1;
                    PQ.push({dist[w], w});
                }
            }
        }
        long long ub = maxMoves;
        for (int i = 0; i < n; i++) {
            if (dist[i] <= ub)
                result++;
            for (auto it : E[i]) {
                int n = it.first, weight = it.second;
                int delta = (ub - dist[i] >= 0) ? ub - dist[i] : 0;
                M[min(i, n)][max(i, n)].push_back(delta);
            }
        }
        for (auto it1 : M)
            for (auto it2 : it1.second) {
                int a = it1.first, b = it2.first;
                auto w = it2.second;
                result += min(w[0], w[1] + w[2]);
            }
        return result;
    }
};

int main(void) {
    Solution s;
}