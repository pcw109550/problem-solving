// 581. Shortest Unsorted Continuous Subarray
#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>

class Solution {
    public:
        int findUnsortedSubarray(std::vector<int>& nums) {
            // O(N)
            int start = -1, end = -1;
            int N = nums.size();
            int Max = nums[0], Min = INT_MAX, Min_idx = 0;
            for (int i = 1; i < N; i++) {
                if (nums[i - 1] > nums[i]) {
                    if (start == -1) {
                        start = i - 1;
                    }
                    Min = std::min(Min, nums[i]);
                    end = i;
                }
                if (nums[i] < Max) {
                    end = i;   
                } else {
                    Max = nums[i];
                }
            }
            if (Min != INT_MAX) {
                for (int i = 0; i < N; i++)
                    if (Min < nums[i]) {
                        start = i;
                        break;
                    }
            }
            return start == -1 ? 0 : end - start + 1;
        }
};

class Solution2 {
    public:
        int findUnsortedSubarray(std::vector<int>& nums) {
            // O(N * log(N))
            std::vector<int> temp = nums;
            std::sort(temp.begin(), temp.end());
            int start = -1, end = -1;
            for (int i = 0; i < nums.size(); i++) {
                if (temp[i] != nums[i]) {
                    if (start == -1)
                        start = i;
                    end = i;
                }
            }
            return start == -1 ? 0 : end - start + 1;
        }
}; 

int main(void) {
    Solution s;
}