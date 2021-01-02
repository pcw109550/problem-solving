// 673. Number of Longest Increasing Subsequence
#include <algorithm>
#include <iostream>
#include <vector>
#include <unordered_map>

class Solution {
    public:
        int findNumberOfLIS(std::vector<int>& nums) {
            // O(N ** 2)
            int result = 0, max_length = 1;
            int D[2000] = {};
            int T[2000] = {};
            for (int i = 0; i < nums.size(); i++) {
                for (int j = 0; j < i; j++) {
                    if (nums[j] < nums[i]) {
                        if (D[i] < D[j] + 1)
                            T[i] = 0;
                        D[i] = std::max(D[i], D[j] + 1);
                        max_length = std::max(max_length, D[i]);
                        if (D[i] == D[j] + 1)
                            T[i] += T[j];
                    }
                }
                if (D[i] == 0) {
                    D[i] = 1;
                    T[i] = 1;
                }
            }
            for (int i = 0; i < nums.size(); i++)
                if (D[i] == max_length)
                    result += T[i]; 
            return result;
        }
};

int main(void) {
    Solution s;
}