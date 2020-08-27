// 27. Remove Element
#include <iostream>
#include <vector>

class Solution {
    public:
        int removeElement(std::vector<int>& nums, int val) {
            // O(N)
            int idx = 0;
            for (int i = 0; i < nums.size(); i++) {
                if (nums[i] != val) {
                    nums[i - idx] = nums[i];
                } else {
                    idx++;
                }
            }
            return nums.size() - idx;
        }
};

int main(void) {
    Solution s;
    std::vector<int> nums {3, 2, 2, 3};
    int val = 3;
    std::cout << s.removeElement(nums, val) << std::endl;
    for (auto it : nums)
        std::cout << it << ' ';
}