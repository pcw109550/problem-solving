// 334. Increasing Triplet Subsequence
#include <algorithm>
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        // Time O(N) Space O(N)
        int N = nums.size();
        if (N < 3)
            return false;
        // stores mins from 0 to i
        vector<int> Mins (N, INT_MAX);
        // stores maxs from N - 1 to i
        vector<int> Maxs (N, INT_MIN);
        for (int i = 0; i < N; i++)
            Mins[i] = min(nums[i], i >= 1 ? Mins[i - 1] : nums[i]);
        for (int i = N - 1; i >= 0; i--)
            Maxs[i] = max(nums[i], i + 1 < N ? Maxs[i + 1] : nums[i]);
        for (int i = 1; i < N - 1; i++)
            if (Mins[i - 1] < nums[i] && nums[i] < Maxs[i + 1])
                return true;
        return false;
    }
};

int main(void) {
    Solution s;
}