// 268. Missing Number
#include <iostream>
#include <vector>

class Solution {
    public:
        int missingNumber(std::vector<int>& nums) {
            // O(N)
            int sum = 0, N = nums.size();
            for (auto num : nums)
                sum += num;
            return N * (N + 1) / 2 - sum;
        }
};

int main(void) {
    Solution s;
}