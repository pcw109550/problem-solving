// 665. Non-decreasing Array
#include <iostream>
#include <vector>

class Solution {
    public:
        bool checkPossibility(std::vector<int>& nums) {
            // O(N)
            bool modified = false;
            int N = nums.size();
            for (int i = 0; i < N - 1; i++) {
                if (nums[i] > nums[i + 1]) {
                    if (modified)
                        return false;
                    modified = true;
                    if (i == 0) {
                        nums[i] = nums[i + 1];
                        continue;
                    }
                    if (nums[i - 1] <= nums[i + 1])
                        nums[i] = nums[i - 1];
                    else
                        nums[i + 1] = nums[i];
                }
            }
            return true;
        }
};

int main(void) {
    Solution s;
}