// 1679. Max Number of K-Sum Pairs
#include <algorithm>
#include <iostream>
#include <vector>
#include <unordered_map>

class Solution {
    public:
        int maxOperations(std::vector<int>& nums, int k) {
            // O(N)
            int result = 0;
            std::unordered_map<int, int> M;
            for (auto num : nums)
                M[num]++;
            for (auto it : M) {
                auto current = it.first;
                if (M.count(k - current))
                    result += std::min(it.second, M[k - current]);
            }
            result /= 2;
            return result;
        }
};

int main(void) {
    Solution s;
}