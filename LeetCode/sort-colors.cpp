// 75. Sort Colors
#include <algorithm>
#include <iostream>
#include <vector>

class Solution {
    public:
        void sortColors(std::vector<int>& nums) {
            // O(N)
            int N = nums.size();
            if (N == 0)
                return;
            int start = 0, end = N - 1;
            for (int i = 0; i < N; i++) {
                if (nums[i] == 2 && i < end) {
                    std::swap(nums[i], nums[end]);
                    end--;
                    i--;
                } else if (nums[i] == 0 && i > start) {
                    std::swap(nums[i], nums[start]);
                    start++;
                    i--;
                }
            }
        }
};

int main(void) {
    Solution s;
    std::vector<int> nums {2, 0, 2, 1, 1, 0};
    s.sortColors(nums);
    for (auto it : nums)
        std::cout << it << ' ';
}