// 1129. Shortest Path with Alternating Colors
#include <algorithm>
#include <iostream>
#include <vector>
#include <climits>
#include <queue>
#include <utility>
using namespace std;

class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& red_edges, vector<vector<int>>& blue_edges) {
        // O(N + E)
        vector<int> result(n, INT_MAX);
        vector<vector<int> > re (n);
        vector<vector<int> > be (n);
        for (auto edge : red_edges)
            re[edge[0]].push_back(edge[1]);
        for (auto edge : blue_edges)
            be[edge[0]].push_back(edge[1]);
        vector<int> r_dist(n);
        vector<int> b_dist(n);
        bfs(re, be, r_dist, false);
        bfs(re, be, b_dist, true);
        for (int i = 0; i < n; i++) {
            result[i] = min(result[i], min(r_dist[i], b_dist[i]));
            if (result[i] == INT_MAX)
                result[i] = -1;
        }
        return result;
    }
    
    void bfs(vector<vector<int>> &re, vector<vector<int>> &be, vector<int>& dist, int start_color) {
        fill(dist.begin(), dist.end(), INT_MAX);
        vector<vector<int> > cur_dist(dist.size(), vector<int> (2, -1));
        vector<vector<vector<bool> > >  vis_col (dist.size(), vector<vector<bool> > (dist.size(), vector<bool>(2, false))); // {red, blue}
        queue<pair<int, bool> > Q; // {pos, color}
        Q.push({0, start_color}); dist[0] = 0; cur_dist[0][false] = cur_dist[0][true] = 0;
        while (!Q.empty()) {
            auto cur = Q.front(); Q.pop();
            int curpos = cur.first;
            bool color = cur.second;
            for (auto neighbor : (color ? be[curpos] : re[curpos])) {
                if (!vis_col[neighbor][curpos][color]) {
                    cur_dist[neighbor][color] = cur_dist[curpos][!color] + 1;
                    vis_col[neighbor][curpos][color] = true;
                    dist[neighbor] = min(dist[neighbor], cur_dist[neighbor][color]);
                    Q.push({neighbor, !color});
                }
            }
        }
    }
};

int main(void) {
    Solution s;
}