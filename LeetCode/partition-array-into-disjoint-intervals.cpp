// 915. Partition Array into Disjoint Intervals
#include <climits>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {
        // O(N)
        int N = nums.size();
        vector<int> Mins (N), Maxs(N);
        int cur = INT_MIN;
        for (int i = 0; i < N; i++) {
            cur = max(cur, nums[i]);
            Mins[i] = cur;
        }
        cur = INT_MAX;
        for (int i = N - 1; i >= 0; i--) {
            cur = min(cur, nums[i]);
            Maxs[i] = cur;
        }
        int result = 0;
        for (int i = 0; i < N - 1; i++)
            if (Mins[i] <= Maxs[i + 1]) {
                result = i + 1;
                break;
            }
        return result;
    }
};

int main(void) {
    Solution s;
}