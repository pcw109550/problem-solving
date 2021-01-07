// 198. House Robber
#include <algorithm>
#include <iostream>
#include <vector>

class Solution {
    public:
        int rob(std::vector<int>& nums) {
            // O(N)
            int N = nums.size();
            int D[101][2] = {};
            for (int i = 0; i < N; i++) {
                D[i + 1][0] = D[i][1] + nums[i];
                D[i + 1][1] = std::max(D[i][0], D[i][1]);
            }
            return std::max(D[N][0], D[N][1]);
        }
};

int main(void) {
    Solution s;
}