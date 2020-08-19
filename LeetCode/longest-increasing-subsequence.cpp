// 300. Longest Increasing Subsequence
#include <algorithm>
#include <iostream>
#include <vector>

class Solution {
    public:
        int lengthOfLIS(std::vector<int>& nums) {
            std::ios_base::sync_with_stdio(false);
            std::cin.tie(NULL);
            std::cout.tie(NULL);
            // O(N * log(N))
            std::vector<int> lis;
            for (auto num : nums) {
                if (lis.size() == 0) {
                    lis.emplace_back(num);
                    continue;
                }
                auto it = lower_bound(lis.begin(), lis.end(), num);
                int len = lis.size();
                if (it == lis.end()) {
                    lis.emplace_back(num);
                    continue;
                }
                lis[it - lis.begin()] = num;
            }
            int result = lis.size();
            return result;
        }
};

int main(void) {
    Solution s;
    std::vector<int> nums {10, 9, 2, 5, 3, 7, 101, 18};
    int result = s.lengthOfLIS(nums);
    std::cout << result;
}