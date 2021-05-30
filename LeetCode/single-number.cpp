// 136. Single Number
#include <iostream>
#include <vector>

class Solution {
    public:
        int singleNumber(std::vector<int>& nums) {
            // O(N)
            int result = 0;
            for (auto num : nums)
                result ^= num;            
            return result;
        }
};

int main(void) {
    Solution s;
}