// 1695. Maximum Erasure Value
#include <algorithm>
#include <iostream>
#include <vector>
#include <unordered_map>

class Solution {
    public:
        int maximumUniqueSubarray(std::vector<int>& nums) {
            // O(N)
            int result = 0;
            std::unordered_map<int, int> M;
            std::vector<int> D(nums.size() + 1, 0);
            for (int i = 0; i < nums.size(); i++)
                D[i + 1] = D[i] + nums[i];
            int base = 0, temp = 0;
            for (int i = 0; i < nums.size(); i++) {
                if (M.count(nums[i]) && M[nums[i]] >= base) {
                    base = M[nums[i]] + 1;
                    temp = D[i + 1] - D[base];
                } else {
                    temp += nums[i];
                }
                result = std::max(result, temp);
                M[nums[i]] = i;
            }
            return result;
        }
};


int main(void) {
    Solution s;
}