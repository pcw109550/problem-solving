// 1437. Check If All 1's Are at Least Length K Places Away
#include <iostream>
#include <vector>

class Solution {
    public:
        bool kLengthApart(std::vector<int>& nums, int k) {
            // O(N)
            int prev = -1;
            for (int i = 0; i < nums.size(); i++) {
                if (nums[i] == 1) {
                    if (prev != -1 && i - prev - 1 < k)
                        return false;
                    prev = i;
                }
            }
            return true;
        }
};

int main(void) {
    Solution s;
}