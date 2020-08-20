// 239. Sliding Window Maximum
#include <algorithm>
#include <iostream>
#include <vector>

class Solution {
    public:
        std::vector<int> maxSlidingWindow(std::vector<int>& nums, int k) {
            // O(n)
            std::vector<int> result;
            int max_pos = std::max_element(nums.begin(), nums.begin() + k) - nums.begin();
            result.emplace_back(nums.at(max_pos));
            for (int i = k; i < nums.size(); i++) {
                if (result.back() <= nums.at(i)) {
                    result.emplace_back(nums.at(i));
                    max_pos = i;
                    continue;
                }
                if (max_pos == i - k) {
                    max_pos = std::max_element(nums.begin() + i - k + 1, nums.begin() + i + 1) - nums.begin();
                    result.emplace_back(nums.at(max_pos));
                    continue;
                }
                result.emplace_back(nums.at(max_pos));
            }
            return result;
        }
};

int main(void) {
    Solution s;
    std::vector<int> nums {7, 2, 4};
    std::vector<int> result = s.maxSlidingWindow(nums, 2);
    for (auto it : result)
        std::cout << it << ' ';
}