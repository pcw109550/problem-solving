// 55. Jump Game
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        // O(N)
        int N = nums.size();
        int p = 0;
        for (int i = 0; i < N; i++) {
            if (i <= p)
                p = max(p, i + nums[i]);
            else
                return false;
        }
        return true;
    }
};

int main(void) {
    Solution s;
}