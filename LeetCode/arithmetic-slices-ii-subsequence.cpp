// 446. Arithmetic Slices II - Subsequence
#include <algorithm>
#include <iostream>
#include <vector>
#include <utility>
using namespace std;

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        // O(N ** 3)
        long long result = 0;
        int N = nums.size();
        vector<vector<pair<long long, long long> > > D(N);
        for (int i = 0; i < N; i++) {
            for (int j = i - 1; j >= 0; j--) {
                long long delta = (long long)nums[i] - nums[j];
                long long cnt = 0;
                for (auto it : D[j])
                    if (it.first == delta)
                        cnt += it.second + 1;
                result += cnt;
                D[i].push_back({delta, cnt});       
            }
        }
        return result;
    }
};

int main(void) {
    Solution s;
}