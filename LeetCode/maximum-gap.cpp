// 164. Maximum Gap
#include <algorithm>
#include <iostream>
#include <vector>
#include <climits>

class Solution {
    public:
        int maximumGap(std::vector<int>& nums) {
            // Time O(N) Space O(N) BucketSort
            int n = nums.size();
            if (n < 2)
                return 0;
            auto lu = std::minmax_element(nums.begin(), nums.end());
            int l = *lu.first, u = *lu.second;
            int gap = std::max((u - l) / (n - 1), 1);
            int m = (u - l) / gap + 1;
            std::vector<int> bucketsMin(m, INT_MAX);
            std::vector<int> bucketsMax(m, INT_MIN);
            for (int num : nums) {
                int k = (num - l) / gap;
                if (num < bucketsMin[k])
                    bucketsMin[k] = num;
                if (num > bucketsMax[k])
                    bucketsMax[k] = num;
            }
            int i = 0, j; 
            gap = bucketsMax[0] - bucketsMin[0];
            while (i < m) {
                j = i + 1;
                while (j < m && bucketsMin[j] == INT_MAX && bucketsMax[j] == INT_MIN)
                    j++;
                if (j == m)
                    break;
                gap = std::max(gap, bucketsMin[j] - bucketsMax[i]);
                i = j;
            }
            return gap;
        }
};


class Solution2 {
    public:
        int maximumGap(std::vector<int>& nums) {
            // O(N * log(N))
            if (nums.size() < 2)
                return 0;
            int result = 0;
            std::sort(nums.begin(), nums.end());
            for (int i = 0; i < nums.size() - 1; i++)
                result = std::max(result, nums[i + 1] - nums[i]);
            return result;
        }
};

int main(void) {
    Solution s;
}