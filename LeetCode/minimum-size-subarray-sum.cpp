// 209. Minimum Size Subarray Sum
#include <algorithm>
#include <iostream>
#include <vector>
#define MAX 1 << 30

class Solution {
    public:
        int minSubArrayLen(int s, std::vector<int>& nums) {
            // O(N * log(N))
            int result = MAX;
            int N = nums.size();
            std::vector<int> sums (N + 1, 0);
            for (int i = 0; i < N; i++)
                sums[i + 1] = sums[i] + nums[i];
            for (int i = 0; i < N; i++) {
                int target = s + sums[i];
                auto bound = std::lower_bound(sums.begin(), sums.end(), target);
                if (bound != sums.end()) {
                    result = std::min(result, static_cast<int>(bound - (sums.begin() + i)));       
                }
            }
            return result == MAX ? 0 : result;
        }
};

class Solution2 {
    public:
        int minSubArrayLen(int s, std::vector<int>& nums) {
            // O(N)
            int result = MAX;
            int start = 0, end = 0, sum = 0;
            while (end < nums.size()) {
                sum += nums[end];
                end++;                
                while (sum >= s) {
                    result = std::min(result, end - start);
                    sum -= nums[start];
                    start++;
                }
            }
            return result == MAX ? 0 : result;
        }
};

int main(void) {
    Solution s;
}