// 523. Continuous Subarray Sum
#include <iostream>
#include <vector>
#include <unordered_map>

class Solution {
    public:
        bool checkSubarraySum(std::vector<int>& nums, int k) {
            // O(N)
            int N = nums.size();
            std::vector<int> D (N + 1, 0);
            std::unordered_map<int, std::vector<int> > temp;
            temp[0].push_back(-1);
            for (int i = 0; i < N; i++) {
                D[i + 1] = (D[i] + nums[i]) % k;
                if (!temp[D[i + 1]].empty())
                    if (i - temp[D[i + 1]][0] > 1)
                        return true;
                temp[D[i + 1]].push_back(i);
            }
            return false;
        }
};

int main(void) {
    Solution s;
}