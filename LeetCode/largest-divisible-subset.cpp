// 368. Largest Divisible Subset
#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        // O(N ** 2) Topological sort
        vector<int> result;
        int N = nums.size();
        sort(nums.begin(), nums.end());
        vector<int> indegree(N, 0);
        vector<vector<int> > neighbors (N, vector<int>());
        for (int i = 0; i < N; i++)
            for (int j = i + 1; j < N; j++) {
                if (nums[j] % nums[i] == 0) {
                    indegree[j]++;
                    neighbors[i].push_back(j);
                }
            }
        vector<int> lengths (N, INT_MIN);
        vector<int> prev (N, -1);
        queue<int> Q;
        for (int i = 0; i < N; i++)
            if (indegree[i] == 0) {
                Q.push(i);
                lengths[i] = 0;
            }
        while (!Q.empty()) {
            auto cur = Q.front(); Q.pop();
            for (auto neighbor : neighbors[cur]) {
                indegree[neighbor]--;
                if (lengths[neighbor] < lengths[cur] + 1) {
                    lengths[neighbor] = lengths[cur] + 1;
                    prev[neighbor] = cur;
                }
                if (indegree[neighbor] == 0) {
                    Q.push(neighbor);
                }
            }
        }
        int max_len = 1, max_idx = 0;
        for (int i = 0; i < N; i++)
            if (max_len < lengths[i] + 1) {
                max_len = lengths[i] + 1;
                max_idx = i;
            }
        int cur = max_idx;
        while (cur != -1) {
            result.push_back(nums[cur]);
            cur = prev[cur];
        }
        return result;
    }
};

int main(void) {
    Solution s;
}
