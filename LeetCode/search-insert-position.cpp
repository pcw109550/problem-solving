// 35. Search Insert Position
#include <algorithm>
#include <iostream>
#include <vector>

class Solution {
    public:
        int searchInsert(std::vector<int>& nums, int target) {
            // O(log(N))
            if (nums.size() == 0)
                return 0;
            int count = nums.size(), step;
            std::vector<int>::iterator it;
            auto first = nums.begin(), last = nums.end();
            while (count > 0) {
                it = first; step = count / 2; std::advance(it, step);
                if (*it < target) {
                    first = ++it;
                    count -= step + 1;
                }
                else count = step;
            }
            return first - nums.begin();
        }
};

class Solution2 {
    public:
        int searchInsert(std::vector<int>& nums, int target) {
            // O(log(N))
            if (nums.size() == 0)
                return 0;
            return std::lower_bound(nums.begin(), nums.end(), target) - nums.begin();
        }
};

int main(void) {
    Solution s;
    std::vector<int> nums {1, 3, 5, 6};
    int target = 5;
    int result = s.searchInsert(nums, target);
    std::cout << result;
}