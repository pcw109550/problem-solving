// 945. Minimum Increment to Make Array Unique
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        // O(N * log(N))
        int result = 0;
        int N = nums.size();
        sort(nums.begin(), nums.end());
        int cur = nums[0];
        for (int i = 1; i < N; i++) {
            if (cur < nums[i])
                cur = nums[i];
            else if (cur == nums[i]) {
                result++;
                cur++;
            } else {
                cur++;
                result += cur - nums[i];
            }
        }
        return result;
    }
};

int main(void) {
    Solution s;
}
