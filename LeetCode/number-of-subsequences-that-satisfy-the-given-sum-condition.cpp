// 1498. Number of Subsequences That Satisfy the Given Sum Condition
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
#define FIELD 1000000007

class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        // O(N * log(N))
        sort(nums.begin(), nums.end());
        int res = 0, N = nums.size(), l = 0, r = N - 1;
        vector<int> pows(N, 1);
        for (int i = 1; i < N; i++)
            pows[i] = pows[i - 1] * 2 % FIELD;
        while (l <= r) {
            if (nums[l] + nums[r] > target)
                r--;
            else
                res = (res + pows[r - l++]) % FIELD;
        }
        return res;
    }
};

int main(void) {
    Solution s;
}
