// 962. Maximum Width Ramp
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        // O(N * log(N))
        int result = 0;
        int N = nums.size();
        vector<vector<int> > D;
        for (int i = 0; i < N; i++)
            D.push_back(vector<int> {nums[i], i});
        sort(D.begin(), D.end());
        int Min = D[0][1];
        for (int i = 1; i < N; i++) {
            int cur = D[i][1];
            result = max(result, cur - Min);
            Min = min(Min, cur);
        }
        return result;
    }
};

int main(void) {
    Solution s;
}