// 229. Majority Element II
#include <iostream>
#include <vector>
#include <unordered_map>

class Solution {
    public:
        std::vector<int> majorityElement(std::vector<int>& nums) {
            // Time O(N) Space O(N)
            std::vector<int> result;
            std::unordered_map<int, int> M;
            for (auto num : nums)
                M[num]++;
            for (auto it : M)
                if (it.second > nums.size() / 3)
                    result.push_back(it.first);
            return result;
        }
};