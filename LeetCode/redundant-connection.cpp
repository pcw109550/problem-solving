// 684. Redundant Connection
#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
#include <unordered_map>
using namespace std;

class Solution {
    vector<vector<int> > neighbors;
    unordered_set<int> S;
    vector<vector<int> > track;
    vector<int> result;
    int result_idx;
    unordered_map<int, int> M;
    bool found;
    int N;
    public:
        vector<int> findRedundantConnection(vector<vector<int>>& edges) {
            // O(N ** 2)
            found = false;
            N = edges.size();
            neighbors = vector<vector<int> > (N + 1, vector<int>());
            for (int i = 0; i < N; i++) {
                int start = edges[i][0];
                int end = edges[i][1];
                neighbors[start].push_back(end);
                neighbors[end].push_back(start);
                M[start * (N + 1) + end] = i;
            }
            S.insert(1);
            traversal(0, 1);
            S.erase(1);
            result = edges[result_idx];
            return result;
        }
    
        void traversal(int prev, int parent) {
            if (found)
                return;
            for (auto child : neighbors[parent]) {
                if (prev == child)
                    continue;
                track.push_back(vector<int> {parent, child});
                if (S.count(child)) {
                    found = true;
                    gen_result();
                    return;
                }
                S.insert(child);
                traversal(parent, child);
                S.erase(child);
                track.pop_back();
            }
        }
              
        inline void gen_result() {
            vector<int> idx;
            int K = track.size();
            int end = track.back()[1];
            for (int i = K - 1; i >= 0; i--) {
                int x = track[i][0];
                int y = track[i][1];
                if (M.count(x * (N + 1) + y))
                    idx.push_back(M[x * (N + 1) + y]);
                else if (M.count(y * (N + 1) + x))
                    idx.push_back(M[y * (N + 1) + x]);
                if (x == end)
                    break;
            }
            sort(idx.begin(), idx.end());
            result_idx = idx.back();
        }  
};

int main(void) {
    Solution s;
}