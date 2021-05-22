// 1048. Longest String Chain
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <queue>
#include <utility>
#include <climits>

class Solution {
    public:
        int longestStrChain(std::vector<std::string>& words) {
            // O(N ** 2) 
            int result = 0;
            int N = words.size();
            std::vector<int> indegree(N, 0);
            std::vector<int> dist(N, 1);
            std::unordered_map<int, std::vector<std::pair<std::string, int> > > M;
            std::vector<std::vector<int> > adj (N, std::vector<int> ());
            int Min_len = INT_MAX, Max_len = INT_MIN;
            for (int i = 0; i < N; i++) {
                int len = words[i].size();
                Min_len = std::min(Min_len, len);
                Max_len = std::max(Max_len, len);
                M[len].push_back({words[i], i});
            }
            for (int i = Min_len; i < Max_len; i++)
                for (auto low : M[i])
                    for (auto high : M[i + 1])
                        if (compare(low.first, high.first)) {
                            adj[low.second].push_back(high.second);
                            indegree[high.second]++;
                        }
            std::queue<int> Q;
            for (int i = 0; i < N; i++)
                if (!indegree[i])
                    Q.push(i);
            while (!Q.empty()) {
                int current = Q.front(); Q.pop();
                result = std::max(result, dist[current]);
                for (auto it : adj[current]) {
                    dist[it] = std::max(dist[it], dist[current] + 1);
                    indegree[it]--;
                    if (!indegree[it])
                        Q.push(it);
                }
            }
            return result;
        }
    
        bool compare(std::string &a, std::string &b) {
            // O(M)
            int num_diff = 0;
            int probe = 0;
            while (num_diff <= 1 && probe < b.size()) {
                if (a[probe] != b[probe + num_diff])
                    num_diff++;
                else
                    probe++;
            }
            return num_diff == 1;
        }
};

int main(void) {
    Solution s;
}