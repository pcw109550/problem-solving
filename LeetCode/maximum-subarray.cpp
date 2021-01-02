// 53. Maximum Subarray
#include <algorithm>
#include <iostream>
#include <vector>

class Solution {
    public:
        int maxSubArray(std::vector<int>& nums) {
            // O(N)
            int temp, result;
            temp = result = nums[0];
            for (int i = 1; i < nums.size(); i++) {
                if (temp > 0)
                    temp += nums[i];
                else
                    temp = nums[i];
                result = std::max(result, temp);
            }
            return result;
        }
};

int main(void) {
    Solution s;
}