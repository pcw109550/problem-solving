// 674. Longest Continuous Increasing Subsequence
#include <iostream>
#include <vector>

class Solution {
    public:
        int findLengthOfLCIS(std::vector<int>& nums) {
            // O(N)
            int N = nums.size();
            if (N == 0)
                return 0;
            int start = -1, result = 1, idx = 0;
            for (int i = 0; i < N; i++) {
                if (!(start == -1 || start < nums[i])) {
                    result = std::max(result, i - idx);
                    idx = i;
                }
                start = nums[i];
            }          
            result = std::max(result, N - idx);
            return result;
        }
};

int main(void) {
    Solution s;
    std::vector<int> nums {1, 3, 5, 2, 4, 7, 9, 1, 2, 3, 4, 5};
    int result = s.findLengthOfLCIS(nums);
    std::cout << result;
}