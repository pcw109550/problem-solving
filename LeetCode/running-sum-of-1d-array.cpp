// 1480. Running Sum of 1d Array
#include <iostream>
#include <vector>

class Solution {
    public:
        std::vector<int> runningSum(std::vector<int>& nums) {
            // O(N)
            std::vector<int> result;
            int sum = 0;
            for (auto num : nums) {
                sum += num;
                result.push_back(sum);
            }
            return result;
        }
};

int main(void) {
    Solution s;
}