// 462. Minimum Moves to Equal Array Elements II
#include <algorithm>
#include <iostream>
#include <vector>
#include <climits>

class Solution {
    public:
        int minMoves2(std::vector<int>& nums) {
            // O(N * log(N))
            int result = 0;
            std::sort(nums.begin(), nums.end());
            int N = nums.size();
            int t1 = nums[N / 2];
            int cand1 = 0;
            for (auto num : nums)
                cand1 += std::abs(t1 - num);
            int t2 = INT_MAX;
            int cand2 = INT_MAX;
            if (N % 2 == 0) {
                cand2 = 0;
                int t2 = nums[N / 2 - 1];
                for (auto num : nums)
                    cand2 += std::abs(t2 - num);
            }
            result = std::min(cand1, cand2);   
            return result;
        }
};

int main(void) {
    Solution s;
}