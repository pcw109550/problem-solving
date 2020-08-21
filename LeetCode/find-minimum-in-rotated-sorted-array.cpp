// 153. Find Minimum in Rotated Sorted Array
#include <algorithm>
#include <iostream>
#include <vector>

class Solution {
    public:
        int findMin(std::vector<int>& nums) {
            // O(log (N))
            int N = nums.size();
            int lo = 0, hi = N - 1, mid;
            while (lo < hi) {
                mid = (lo + hi) / 2;
                if (nums[mid] > nums[hi])
                    lo = mid + 1;
                else
                    hi = mid;
            }
            return nums[lo];
        }
};

int main(void) {
    Solution s;
    std::vector<int> nums {3, 4, 5, 1, 2};
    int result = s.findMin(nums);
    std::cout << result;
}