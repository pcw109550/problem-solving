// 31. Next Permutation
#include <algorithm>
#include <vector>
#include <iostream>

class Solution {
    public:
        void nextPermutation(std::vector<int>& nums) {
            // O(N)
            int n = nums.size(), k, l;
            for (k = n - 2; k >= 0; k--) {
                if (nums[k] < nums[k + 1]) {
                    break;
                }
            }
            if (k < 0) {
                std::reverse(nums.begin(), nums.end());
            } else {
                for (l = n - 1; l > k; l--) {
                    if (nums[l] > nums[k]) {
                        break;
                    }
                } 
                std::swap(nums[k], nums[l]);
                std::reverse(nums.begin() + k + 1, nums.end());
            }
        }
};

class Solution2 {
    public:
        void nextPermutation(std::vector<int>& nums) {
            // O(N log(N))
            int N = nums.size(), idx = -1;
            if (N == 1)
                return;
            for (int i = N - 1; i >= 1; i--) {
                if (nums[i - 1] < nums[i]) {
                    idx = i - 1;
                    break;
                }
            }
            if (idx == -1) { // next arrangement not possible
                std::reverse(nums.begin(), nums.end());
                return;
            }
            int idy = -1, Min = 1 << 30;
            for (int i = idx + 1; i < N; i++) {
                if (nums[idx] < nums[i]) {
                    if (Min > nums[i]) {
                        Min = nums[i];
                        idy = i;
                    }
                }
            }
            std::swap(nums[idx], nums[idy]);
            std::sort(nums.begin() + idx + 1, nums.end());
        }
};

int main(void) {
    Solution s;
}