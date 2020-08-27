// 540. Single Element in a Sorted Array
#include <iostream>
#include <vector>

class Solution {
    public:
        int singleNonDuplicate(std::vector<int>& nums) {
            // O(log(N))
            if (nums.size() == 1)
                return nums.at(0);
            int lo = 0, hi = nums.size() - 1, mid;
            while (lo <= hi) {
                mid = (lo + hi) / 2;
                if (nums[mid] == nums[mid + 1]) {
                    if (mid % 2 == 0)
                        lo = mid + 1;
                    else
                        hi = mid - 1;
                } else {
                    if (mid % 2 == 0)
                        hi = mid - 1;
                    else
                        lo = mid + 1;
                }   
            }
            int result = nums[lo];
            return result;
        }
};

int main(void) {
    Solution s;
    std::vector<int> nums {1, 1, 3, 3, 4, 4, 6, 6, 7, 7, 8, 8, 10, 10, 14, 14, 17, 17, 21, 21, -1};
    std::cout << s.singleNonDuplicate(nums);
}