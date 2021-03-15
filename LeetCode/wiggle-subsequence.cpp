// 376. Wiggle Subsequence
#include <algorithm>
#include <iostream>
#include <vector>

class Solution {
    public:
        int wiggleMaxLength(std::vector<int>& nums) {
            // O(N)      
            int result = 1;
            int N = nums.size();
            std::vector<int> dec(N, 0); dec[0] = 1;
            std::vector<int> inc(N, 0); inc[0] = 1;
            for (int i = 1; i < N; i++) {
                if (nums[i] < nums[i - 1]) {
                    inc[i] = inc[i - 1];
                    dec[i] = std::max(dec[i], inc[i - 1] + 1);
                } else if (nums[i] > nums[i - 1]) {
                    inc[i] = std::max(inc[i], dec[i - 1] + 1);
                    dec[i] = dec[i - 1];
                } else {
                    inc[i] = inc[i - 1];
                    dec[i] = dec[i - 1];
                }
                result = std::max(result, std::max(inc[i], dec[i]));
            }
            return result;
        }
};

int main(void) {
    Solution s;
}