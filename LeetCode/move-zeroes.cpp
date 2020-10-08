// 283. Move Zeroes
#include <iostream>
#include <vector>

class Solution {
    public:
        void moveZeroes(std::vector<int>& nums) {
            // O(N)
            int k = 0;
            for (int i = 0; i < nums.size(); i++)
                if (nums[i] != 0)
                    std::swap(nums[k++], nums[i]);
        }
};

int main(void) {
    Solution s;
    std::vector<int> nums {4, 12, 0, 3, 12};
    s.moveZeroes(nums);
    for (auto &num : nums)
        std::cout << num << ' ';
}