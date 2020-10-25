// 189. Rotate Array
#include <algorithm>
#include <iostream>
#include <vector>

class Solution {
    public:
        void rotate(std::vector<int>& nums, int k) {
            //O(N)
            int len = nums.size();
            if (len <= 1)
                return;
            k %= len;
            std::reverse(nums.begin(), nums.end());
            std::reverse(nums.begin(), nums.begin() + k);
            std::reverse(nums.begin() + k, nums.end());
        }
};

int main(void) {
    Solution s;
    std::vector<int> nums {1, 2, 3, 4, 5, 6, 7};
    int k = 3;
    s.rotate(nums, k);
    for (auto &it: nums)
        std::cout << it << ' ';
}