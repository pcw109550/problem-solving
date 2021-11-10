// 154. Find Minimum in Rotated Sorted Array II
#include <algorithm>
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
    int result = INT_MAX;
public:
    int findMin(vector<int>& nums) {
        // O(N)
        int N = nums.size();
        search(nums, 0, N - 1);
        return result;
    }
    
    void search(vector<int> &nums, int lo, int hi) {
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (nums[lo] == nums[mid] && nums[mid] == nums[hi]) {
                search(nums, lo, mid);
                search(nums, mid + 1, hi);
                break;   
            }
            if (nums[lo] <= nums[mid] && nums[mid] <= nums[hi])
                hi = mid;
            else if (nums[lo] <= nums[mid] && nums[mid] > nums[hi])
                lo = mid + 1;
            else if (nums[lo] > nums[mid] && nums[mid] <= nums[hi]) {
                hi = mid;
            } else if (nums[lo] > nums[mid] && nums[mid] > nums[hi])
                break; // never happen
        }
        result = min(result, nums[lo]);
    }
};

int main(void) {
    Solution s;
}