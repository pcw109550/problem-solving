// 162. Find Peak Element
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        // O(log(N))
        int result = 0;
        int N = nums.size();
        int lo = 0, hi = N - 1;
        int mi = 0;
        while (lo < hi) {
            mi = lo + (hi - lo) / 2;
            if (nums[mi] > nums[mi + 1])
                hi = mi;
            else
                lo = mi + 1;
        }
        return lo;
    }
};

int main(void) {
    Solution s;
}