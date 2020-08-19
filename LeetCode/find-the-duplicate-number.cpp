// 287. Find the Duplicate Number
#include <iostream>
#include <vector>

class Solution {
    public:
        int findDuplicate(std::vector<int>& nums) {
            std::ios_base::sync_with_stdio(false);
            std::cin.tie(NULL);
            std::cout.tie(NULL);
            // Time O(n) Space O(1)
            // Floyd's cycle finding algorithm
            int fast = 0, slow = 0;
            do {
                fast = nums[nums[fast]];
                slow = nums[slow];
            } while (slow != fast);
            slow = 0;
            while (fast != slow) {
                fast = nums[fast];
                slow = nums[slow];
            }
            return slow;
        }
};

int main(void) {
    Solution s;
    std::vector<int> nums {3, 1, 3, 4, 2};
    int result = s.findDuplicate(nums);
    std::cout << result;
}