// 47. Permutations II
#include <algorithm>
#include <iostream>
#include <vector>

class Solution {
    int N;
    public:
        std::vector<std::vector<int> > permuteUnique(std::vector<int>& nums) {
            // O(N! * N)
            std::vector<std::vector<int> > result;
            N = nums.size();
            result.push_back(nums);
            while (true) {
                auto next = next_permutation(result.back());
                if (next != result[0])
                    result.push_back(next);
                else
                    break;
            }
            return result;
        }
    
        std::vector<int> next_permutation(std::vector<int> nums) {
            int l = -1, r = -1;
            for (int i = N - 1; i >= 1; i--)
                if (nums[i - 1] < nums[i]) {
                    l = i - 1;
                    break;
                }
            if (l == -1) {
                std::reverse(nums.begin(), nums.end());
            } else {
                for (int i = N - 1; i > l; i--)
                    if (nums[l] < nums[i]) {
                        r = i;
                        break;
                    }
                std::swap(nums[l], nums[r]);
                std::reverse(nums.begin() + l + 1, nums.end());
            }
            return nums;
        }
};

int main(void) {
    Solution s;
}