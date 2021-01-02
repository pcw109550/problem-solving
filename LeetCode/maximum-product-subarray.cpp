// 152. Maximum Product Subarray
#include <algorithm>
#include <iostream>
#include <vector>

class Solution {
    public:
        int maxProduct(std::vector<int>& nums) {
            // O(N)
            int m, M, next_m, next_M, result;
            m = M = result = nums[0];
            for (int i = 1; i < nums.size(); i++) {
                next_M = std::max(nums[i], M * nums[i]);
                next_M = std::max(next_M, m * nums[i]);
                next_m = std::min(nums[i], M * nums[i]);
                next_m = std::min(next_m, m * nums[i]);
                m = next_m;
                M = next_M;
                result = std::max(result, M);
            }
            return result;
        }
};

class Solution2 {
    public:
        int maxProduct(std::vector<int>& nums) {
            // O(N ** 2), TLE
            int result = -(1 << 30);
            int N = nums.size();
            for (int i = 0; i < N; i++) {
                int base = nums[i];
                result = std::max(result, base);
                for (int j = i + 1; j < N; j++) {
                    base *= nums[j];
                    result = std::max(result, base);
                }
            }
            return result;
        }
};

int main(void) {
    Solution s;
}