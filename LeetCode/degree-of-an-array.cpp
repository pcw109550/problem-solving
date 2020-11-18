// 697. Degree of an Array
#include <algorithm>
#include <iostream>
#include <vector>
#define MAX 50000

class Solution {
    public:
        int findShortestSubArray(std::vector<int>& nums) {
            // O(N)
            int start[MAX], end[MAX], degree[MAX] = {};
            int max_degree = -1;
            std::fill(start, start + MAX, -1);
            std::fill(end, end + MAX, -1);
            for (int i = 0; i < nums.size(); i++) {
                degree[nums[i]]++;
                max_degree = std::max(max_degree, degree[nums[i]]);
                if (start[nums[i]] == -1)
                    start[nums[i]] = end[nums[i]] = i;
                else
                    end[nums[i]] = i;
            }
            int Min = MAX;
            for (int i = 0; i < MAX; i++)
                if (degree[i] == max_degree)
                    Min = std::min(Min, end[i] - start[i] + 1);
            return Min;
        }
};

int main(void) {
    Solution s;
    std::vector<int> nums {1,2,2,3,1};
    std::cout << s.findShortestSubArray(nums);
}