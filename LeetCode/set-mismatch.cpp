// 645. Set Mismatch
#include <iostream>
#include <vector>
#include <unordered_set>

class Solution {
    public:
        std::vector<int> findErrorNums(std::vector<int>& nums) {
            // O(N)
            std::unordered_set<int> S;
            int N = nums.size();
            int target = -1, sum = 0;
            for (auto num : nums) {
                if (S.count(num))
                    target = num;
                else
                    S.insert(num);
                sum += num;
            }
            std::vector<int> result {target, N * (N + 1) / 2 - (sum - target)};
            return result;
        }
};

int main(void) {
    Solution s;
}