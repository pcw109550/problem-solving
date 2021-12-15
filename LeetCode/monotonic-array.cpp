// 896. Monotonic Array#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        // O(N)
        int l = 0, r = 0, N = nums.size();
        for (int i = 0; i < N - 1; i++) {
            if (nums[i] <= nums[i + 1])
                l++;
            if (nums[i] >= nums[i + 1])
                r++;
        } 
        return l == N - 1 || r == N - 1;
    }
};

int main(void) {
    Solution s;
}