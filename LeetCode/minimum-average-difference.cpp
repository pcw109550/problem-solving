#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        // O(N)
        int N = nums.size();
        long long result = INT_MAX;
        long long Min = INT_MAX;
        long long sum = accumulate(nums.begin(), nums.end(), 0L);
        long long acc = 0;
        for (long long i = N - 1; i >= 0; i--) {
            long long la = (sum - acc) / (i + 1);
            long long lb = i == N - 1 ? 0 : acc / (N - i - 1);
            if (Min >= abs(la - lb)) {
                Min = abs(la - lb);
                result = i;
            }
            acc += nums[i];
        }
        if (Min == INT_MAX)
            result = 0;
        return result;
    }
};