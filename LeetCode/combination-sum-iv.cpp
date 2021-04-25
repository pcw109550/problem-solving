// 377. Combination Sum IV
#include <algorithm>
#include <iostream>
#include <vector>
#include <unordered_map>


class Solution {
    public:
        int combinationSum4(std::vector<int>& nums, int target) {
            // O(N * M)
            std::vector<unsigned int> result(target + 1);
            result[0] = 1;
            for (int i = 1; i <= target; ++i) {
                for (int x : nums) {
                    if (i >= x) result[i] += result[i - x];
                }
            }
            return result[target];
        }
};


class Solution2 {
    int N, result;
    std::unordered_map<int, int> track;
    public:
        int combinationSum4(std::vector<int>& nums, int target) {
            // TLE
            N = nums.size();
            std::sort(nums.begin(), nums.end(), std::greater<int>());
            backtrack(nums, 0, target);
            return result;
        }
    
        void backtrack(std::vector<int> &nums, int idx, int t) {
            if (t == 0) {
                std::vector<int> temp;
                int total = 0;
                for (auto it : track) {
                    total += it.second;
                    for (int i = 1; i <= it.second; i++)
                        temp.push_back(i);
                }
                int sub_result = 1;
                for (int i = 1; i <= total; i++) {
                    sub_result *= i;
                    sub_result /= temp[i - 1];
                }
                result += sub_result;
                return;
            }
            for (int i = idx; i < N; i++) {
                if (nums[i] <= t) {
                    track[nums[i]]++;
                    backtrack(nums, i, t - nums[i]);
                    track[nums[i]]--;
                }
            }
        }
};

int main(void) {
    Solution s;
}