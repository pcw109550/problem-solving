// 1877. Minimize Maximum Pair Sum in Array
#include <algorithm>
#include <iostream>
#include <vector>
#include <climits>

class Solution {
    public:
        int minPairSum(std::vector<int>& nums) {
            // O(N * log(N))
            std::sort(nums.begin(), nums.end());
            int result = INT_MIN;
            for (int i = 0; i < nums.size() / 2; i++)
                result = std::max(result, nums[i] + nums[nums.size() - 1 - i]);
            return result;
        }
};

int main(void) {
    Solution s;
}