// 922. Sort Array By Parity II
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        // Time O(N) Space O(1)
        int N = nums.size();
        int p1 = N - 2, p2 = N - 1;
        for (int i = 0; i < N; i++) {
            if (i % 2 == nums[i] % 2)
                continue;
            if (i % 2 == 1 && nums[i] % 2 == 0)
                while (p1 > i && nums[i] % 2 == 0) {
                    if (nums[p1] % 2 == 1) {
                        swap(nums[i], nums[p1]);
                        break;
                    }
                    p1 -= 2;
                }
            else if (i % 2 == 0 && nums[i] % 2 == 1)
                while (p2 > i && nums[i] % 2 == 1) {
                    if (nums[p2] % 2 == 0) {
                        swap(nums[i], nums[p2]);
                        break;
                    }
                    p2 -= 2;
                }
        }
        return nums;
    }
};

int main(void) {
    Solution s;
}