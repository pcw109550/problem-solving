// 1749. Maximum Absolute Sum of Any Subarray
#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

class Solution {
    public:
        int maxAbsoluteSum(std::vector<int>& nums) {
            // O(N)
            int result = 0;
            int Max = 0, Min = 0, acc = 0, temp;
            for (auto num : nums) {
                acc += num;
                temp = std::max(std::abs(acc - Max), std::abs(acc - Min));
                result = std::max(result, temp);
                Max = std::max(Max, acc);
                Min = std::min(Min, acc);
            }
            return result;
        }
};

int main(void) {
    Solution s;
}