// 494. Target Sum
#include <iostream>
#include <vector>
#include <unordered_map>

class Solution {
    public:
        int findTargetSumWays(std::vector<int>& nums, int S) {
            // O(L * N)
            int N = nums.size();
            int result = 0;
            std::unordered_map<int, int> temp, next_temp;
            temp[nums[0]]++;
            temp[-nums[0]]++;
            for (int i = 1; i < N; i++) {
                for (auto it : temp) {
                    next_temp[it.first + nums[i]] += it.second;
                    next_temp[it.first - nums[i]] += it.second;
                }
                temp = next_temp;
                next_temp.clear();
            }
            return temp.find(S) == temp.end() ? 0 : temp[S];
        }
};

int main(void) {
    Solution s;
}