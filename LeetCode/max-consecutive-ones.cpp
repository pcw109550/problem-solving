// 485. Max Consecutive Ones
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        // Time O(N) Space O(1)
        int N = nums.size();
        int result = 0;
        int start = -1;
        for (int i = 0; i < N; i++) {
            if (nums[i] == 1)
                result = max(result, i - start);
            else
                start = i;
        }
        return result;
    }
};

int main(void) {
    Solution s;
}