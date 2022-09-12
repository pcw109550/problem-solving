#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        // O(N)
        int N = nums.size();
        long long sum = accumulate(nums.begin(), nums.end(), 0l);
        long long acc = 0;
        int result = 0;
        for (int i = 0; i < N - 1; i++) {
            acc += nums[i];
            long long l = acc, r = sum - acc;
            if (l >= r)
                result++;
        }
        return result;
    }
};