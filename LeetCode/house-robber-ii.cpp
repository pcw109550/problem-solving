// 213. House Robber II
#include <algorithm>
#include <iostream>
#include <vector>

class Solution {
    public:
        int rob(std::vector<int>& nums) {
            // O(N)
            if (nums.size() == 1)
                return nums[0];
            int D[100][2] = {};
            int result = 0;
            D[0][0] = nums[0];
            for (int i = 1; i < nums.size(); i++) {
                D[i][0] = D[i - 1][1] + nums[i];
                D[i][1] = std::max(D[i - 1][0], D[i - 1][1]);
            }
            result = D[nums.size() - 1][1];
            D[0][0] = 0;
            for (int i = 1; i < nums.size(); i++) {
                D[i][0] = D[i - 1][1] + nums[i];
                D[i][1] = std::max(D[i - 1][0], D[i - 1][1]);
            }
            result = std::max(result, D[nums.size() - 1][0]);
            return result;         
        }
};

int main(void) {
    Solution s;
}