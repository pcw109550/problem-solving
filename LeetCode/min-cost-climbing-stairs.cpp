// 746. Min Cost Climbing Stairs
#include <algorithm>
#include <iostream>
#include <vector>

class Solution {
    public:
        int minCostClimbingStairs(std::vector<int>& cost) {
            // O(N)
            int N = cost.size();
            for (int i = 2; i < N; i++)
                cost[i] += std::min(cost[i - 1], cost[i - 2]);
            return std::min(cost[N - 1], cost[N - 2]);
        }
};

int main(void) {
    Solution s;
}