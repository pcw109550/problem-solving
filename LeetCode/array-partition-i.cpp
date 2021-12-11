// 561. Array Partition I
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        // O(N * log(N))
        int N = nums.size();
        int result = 0;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < N; i += 2)
            result += nums[i];
        return result;
    }
};

int main(void) {
    Solution s;
}