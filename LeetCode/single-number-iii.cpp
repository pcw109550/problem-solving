// 260. Single Number III
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        // Time O(N) Space O(1)
        vector<int> result(2, 0);
        long long a_xor_b = 0, N = nums.size();
        for (int i = 0; i < N; i++) 
            a_xor_b ^= nums[i];
        int last = a_xor_b & (~(a_xor_b - 1));
        for (int i = 0; i < N; i++) {
            if ((last & nums[i]) != 0)
                result[0] ^= nums[i];
            else
                result[1] ^= nums[i];
        }
        return result;
    }
};

int main(void) {
    Solution s;
}