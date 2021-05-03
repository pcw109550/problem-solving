// 45. Jump Game II
#include <algorithm>
#include <iostream>
#include <vector>
#include <climits>

class Solution {
    public:
        int jump(std::vector<int>& nums) {
            // O(N)
            int N = nums.size(), step = 0, start = 0, end = 0;
            while (end < N - 1) {
                step++; 
                int maxend = end + 1;
                for (int i = start; i <= end; i++) {
                    if (i + nums[i] >= N - 1)
                        return step;
                    maxend = std::max(maxend, i + nums[i]);
                }
                start = end + 1;
                end = maxend;
            }
            return step;
        }
};

class Solution2 {
    public:
        int jump(std::vector<int>& nums) {
            // O(N ** 2)
            int N = nums.size();
            std::vector<int> D (N, INT_MAX);
            D[0] = 0;
            for (int i = 0; i < N; i++)
                for (int j = 0; j < i; j++)
                    if (j + nums[j] >= i)
                        D[i] = std::min(D[i], D[j] + 1);
            return D[N - 1];
        }
};

int main(void) {
    Solution s;
}