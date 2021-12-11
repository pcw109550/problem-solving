// 2059. Minimum Operations to Convert Number
#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int minimumOperations(vector<int>& nums, int start, int goal) {
        // O(N * K)
        int result = 0;
        int N = nums.size();
        long long G = goal;
        unordered_map<long long, int> visited;
        visited[start] = 0;
        queue<long long> Q; Q.push(start);
        while (!Q.empty()) {
            long long x = Q.front(); Q.pop();
            for (int i = 0; i < N; i++) {
                if (!visited.count(x + nums[i])) {
                    if (G == x + nums[i])
                        return visited[x] + 1;
                    if (0 <= (x + nums[i]) && (x + nums[i]) <= 1000) {
                        visited[x + nums[i]] = visited[x] + 1;
                        Q.push(x + nums[i]);
                    }
                }
                if (!visited.count(x - nums[i])) {
                    if (G == x - nums[i])
                        return visited[x] + 1;
                    if (0 <= (x - nums[i]) && (x - nums[i]) <= 1000) {
                        visited[x - nums[i]] = visited[x] + 1;
                        Q.push(x - nums[i]);
                    }
                }
                if (!visited.count(x ^ nums[i])) {
                    if (G == (x ^ nums[i]))
                        return visited[x] + 1;
                    if (0 <= (x ^ nums[i]) && (x ^ nums[i]) <= 1000) {
                        visited[x ^ nums[i]] = visited[x] + 1;
                        Q.push(x ^ nums[i]);
                    }
                }
            }
        }
        return -1;
    }
};

int main(void) {
    Solution s;
}