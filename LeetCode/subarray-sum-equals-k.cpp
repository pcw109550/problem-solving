// 560. Subarray Sum Equals K
#include <iostream>
#include <unordered_map>
#include <vector>

class Solution {
    public:
        int subarraySum(std::vector<int>& nums, int k) {
            // O(N)
            int result = 0;
            std::unordered_map<int, int> M;
            M[0] = 1;
            int acc = 0;
            for (auto num : nums) {
                acc += num;
                result += M[acc - k];
                M[acc]++;
            }
            return result;
        }
};

int main(void) {
    Solution s;
}