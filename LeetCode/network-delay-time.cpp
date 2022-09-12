#include <algorithm>
#include <iostream>
#include <vector>
#include <climits>
#include <queue>
using namespace std;

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // O(N + E * log(N)) Dijkstra
        int result = -1;
        int N = n, M = times.size();
        int cnt = 0;
        vector<vector<pair<int, int> > > neighbors (N, vector<pair<int, int> >());
        vector<int> distances(N, INT_MAX);
        for (int i = 0; i < M; i++) {
            int a = times[i][0] - 1, b = times[i][1] - 1, w = times[i][2];
            neighbors[a].push_back({b, w});
        }
        priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > PQ;
        distances[k - 1] = 0;
        for (auto neighbor : neighbors[k - 1]) {
            int b = neighbor.first, w = neighbor.second;
            PQ.push({w, b});
        }
        while (!PQ.empty()) {
            auto cur = PQ.top(); PQ.pop();
            int d = cur.first, a = cur.second;
            if (distances[a] <= d)
                continue;
            distances[a] = d;            
            for (auto neighbor : neighbors[a]) {
                int b = neighbor.first, w = neighbor.second + d;
                PQ.push({w, b});
            }
        }
        for (auto distance : distances) {
            if (distance == INT_MAX)
                return -1;
            result = max(result, distance);
        }
        return result;
    }
};