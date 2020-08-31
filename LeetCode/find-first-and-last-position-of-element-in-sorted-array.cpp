// 34. Find First and Last Position of Element in Sorted Array
#include <algorithm>
#include <iostream>
#include <vector>

class Solution {
    public:
        std::vector<int> searchRange(std::vector<int>& nums, int target) {
            // O(log(N))
            std::vector<int> result;
            if (!std::binary_search(nums.begin(), nums.end(), target))
                return std::vector<int> {-1, -1};
            auto lb = std::lower_bound(nums.begin(), nums.end(), target);
            auto ub = std::upper_bound(nums.begin(), nums.end(), target);
            result.emplace_back(lb - nums.begin());
            result.emplace_back(ub - nums.begin() - 1);
            return result;
        }
};

int main(void) {
    Solution s;
    std::vector<int> nums {5, 5, 5, 7, 7, 7, 7, 9, 10, 10};
    int target = 8;
    auto result = s.searchRange(nums, target);
    for (auto it : result)
        std::cout << it << ' ';
}