// 1748. Sum of Unique Elements
#include <iostream>
#include <vector>
#include <unordered_map>

class Solution {
    public:
        int sumOfUnique(std::vector<int>& nums) {
            // O(N)
            std::unordered_map<int, int> M;
            int result = 0;
            for (auto num : nums)
                M[num]++;
            for (auto it : M)
                if (it.second == 1)
                    result += it.first;
            return result;
        }
};

int main(void) {
    Solution s;
}