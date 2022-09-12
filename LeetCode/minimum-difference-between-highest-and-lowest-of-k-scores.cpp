#include <algorithm>
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        // O(N * log(N))
        int N = nums.size(), result = INT_MAX;
        sort(nums.begin(), nums.end());
        for (int i = 0; i <= N - k; i++)
            result = min(result, nums[i + k - 1] - nums[i]);
        return result;
    }
};