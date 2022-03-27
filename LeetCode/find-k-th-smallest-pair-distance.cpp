// 719. Find K-th Smallest Pair Distance
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        // O(N * log(M))
        int result = 0;
        int N = nums.size();
        sort(nums.begin(), nums.end());
        int lo = 0, hi = nums[N - 1] - nums[0];
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            int cur_cnt = count(nums, mid);
            if (cur_cnt < k)
                lo = mid + 1;
            else
                hi = mid;
        }
        result = lo;
        return result;
    }
    
    int count(vector<int> &nums, int target) {
        // O(N) using two pointers
        int N = nums.size(), lo = 0, hi = 1;
        int result = 0;
        while (lo < N && hi < N) {
            if (nums[hi] - nums[lo] <= target) {
                result += hi - lo;
                hi++;
            } else
                lo++;
        }
        return result;
    }
};

int main(void) {
    Solution s;
}
