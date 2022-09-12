#include <iostream>
#include <cmath>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int findClosestNumber(vector<int>& nums) {
        // O(N)
        int result = INT_MIN;
        int dist = INT_MAX;
        int N = nums.size();
        for (int i = 0; i < N; i++)
            if (dist > abs(nums[i])) {
                dist = abs(nums[i]);
                result = nums[i];
            } else if (dist == abs(nums[i]))
                result = max(result, nums[i]);
        return result;
    }
};