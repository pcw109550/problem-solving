// 795. Number of Subarrays with Bounded Maximum
#include <iostream>
#include <vector>

class Solution {
    public:
        int numSubarrayBoundedMax(std::vector<int>& nums, int left, int right) {
            // O(N)
            int N = nums.size();
            int start = 0, end = -1;
            int result = 0, cnt = 0;
            for (int i = 0; i < N; i++) {
                if (nums[i] > right) {
                    cnt = 0;
                    for (int idx = start; idx <= end; idx++) {
                        if (left <= nums[idx] && nums[idx] <= right)
                            cnt = idx - start + 1;
                        result += cnt;
                    }
                    start = i + 1;
                    end = i;
                } else {
                    end++;
                }
            }
            cnt = 0;
            if (start <= end) {
                for (int idx = start; idx <= end; idx++) {
                    if (left <= nums[idx] && nums[idx] <= right)
                        cnt = idx - start + 1;
                    result += cnt;
                }
            }
            return result;
        }
};

int main(void) {
    Solution s;
}