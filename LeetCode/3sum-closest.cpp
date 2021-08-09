// 16. 3Sum Closest
#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>
#include <climits>
using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        // O(N ** 2)
        int result = 0;
        int delta = INT_MAX;
        int N = nums.size();
        sort(nums.begin(), nums.end());
        for (int i = 0; i < N - 2; i++) {
            int s = i + 1, e = N - 1;
            while (s < e) {
                int sum = nums[i] + nums[s] + nums[e];
                if (delta > abs(target - sum)) {
                    delta = abs(target - sum);
                    result = sum;
                }
                if (sum > target)
                    e--;
                else if (sum < target)
                    s++;
                else
                    return target;
            }
            
        }
        return result;
    }
};

int main(void) {
    Solution s;
}