// 135. Candy
#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

class Solution {
    public:
        int candy(vector<int>& ratings) {
            // O(N)
            int result = 0;
            int N = ratings.size();
            vector<int> indegree (N, 0);
            vector<vector<int> > neighbors (N, vector<int> ());
            for (int i = 0; i < N - 1; i++) {
                if (ratings[i] < ratings[i + 1]) {
                    neighbors[i].push_back(i + 1);
                    indegree[i + 1]++;
                } else if (ratings[i] > ratings[i + 1]) {
                    neighbors[i + 1].push_back(i);
                    indegree[i]++;
                }
            }
            queue<pair<int, int> > Q; // {idx, candy}
            for (int i = 0; i < N; i++)
                if (!indegree[i]) {
                    Q.push({i, 1});
                    result += 1;
                }
            while (!Q.empty()) {
                auto cur = Q.front(); Q.pop();
                for (auto neighbor : neighbors[cur.first]) {
                    indegree[neighbor]--;
                    if (!indegree[neighbor]) {
                        Q.push({neighbor, cur.second + 1});
                        result += cur.second + 1;
                    }
                }
            }
            return result;
        }
};

int main(void) {
    Solution s;
}