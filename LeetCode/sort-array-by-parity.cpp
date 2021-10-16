// 905. Sort Array By Parity
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        // Time O(N) Space O(1)
        int N = nums.size();
        int p = N - 1;
        for (int i = 0; i < N; i++) {
            if (nums[i] % 2 == 0)
                continue;
            while (i < p && nums[p] % 2 == 1)
                p--;
            swap(nums[i], nums[p]);
        }
        return nums;
    }
};

int main(void) {
    Solution s;
}