// 1671. Minimum Number of Removals to Make Mountain Array
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        // O(N ** 2) LIS
        int N = nums.size();
        int result = N;
        vector<int> D1(N, 1), D2(N, 1);
        D1[0] = 1;
        for (int i = 1; i < N; i++)
            for (int j = 0; j < i; j++)
                if (nums[j] < nums[i])
                    D1[i] = max(D1[i], 1 + D1[j]);        
        D2[N - 1] = 1;
        for (int i = N - 2; i >= 0; i--)
            for (int j = N - 1; j > i; j--)
                if (nums[i] > nums[j])
                    D2[i] = max(D2[i], 1 + D2[j]);
        for (int i = 1; i < N - 1; i++)
            if (D1[i] > 1 && D2[i] > 1)
                result = min(result, N - D1[i] - D2[i] + 1);
        return result;
    }
};

int main(void) {
    Solution s;
}
