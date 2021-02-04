// 594. Longest Harmonious Subsequence
#include <algorithm>
#include <iostream>
#include <vector>
#include <map>

class Solution {
    public:
        int findLHS(std::vector<int>& nums) {
            // O(N * log(N))
            int result = 0;
            std::map<int, int> M;
            for (auto num : nums)
                M[num]++;
            auto it = M.begin();
            for (int i = 1; i < M.size(); i++) {
                int a = it->first, b = it->second;
                it++;
                int c = it->first, d = it->second;
                if (c - a == 1)
                    result = std::max(result, b + d);
            }
            return result;
        }
};

int main(void) {
    Solution s;
}