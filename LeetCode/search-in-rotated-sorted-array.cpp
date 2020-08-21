// 33. Search in Rotated Sorted Array
#include <algorithm>
#include <iostream>
#include <vector>

class Solution {
    public:
        int search(std::vector<int>& nums, int target) {
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
            int rot = lo, mid_shifted;
            lo = 0; hi = N - 1;
            while (lo <= hi) {
                mid = (lo + hi) / 2;
                mid_shifted = (mid + rot) % N;
                if (nums[mid_shifted] == target)
                    return mid_shifted;
                if (nums[mid_shifted] < target)
                    lo = mid + 1;
                else
                    hi = mid - 1;
            }
            return -1;
        }
};

class Solution2 {
    public:
        int search(std::vector<int>& nums, int target) {
            // O(N * log(N))
            if (nums.size() == 0)
                return -1;
            int idx = -1;
            for (int i = 0; i < nums.size() - 1; i++) {
                if (nums[i] > nums[i + 1]) {
                    idx = i;
                    break;
                }
            }
            auto it = std::lower_bound(nums.begin(), nums.begin() + idx + 1, target);
            if (it != nums.begin() + idx + 1 && *it == target)   
                return it - nums.begin();
            it = std::lower_bound(nums.begin() + idx + 1, nums.end(), target);
            if (it != nums.end() && *it == target)
                return it - nums.begin();
            return -1;
        }
};

int main(void) {
    Solution s;
    std::vector<int> nums {1, 2, 0};
    int target = 0;
    int result = s.search(nums, target);
    std::cout << result;
}