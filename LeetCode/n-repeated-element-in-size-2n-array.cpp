// 961. N-Repeated Element in Size 2N Array
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        // Time O(N) Space O(1)
        int N = nums.size();
        if (N % 4 == 2) {
            nums.push_back(13337);
            nums.push_back(13338); 
            N += 2;
        }
        for (int i = 0; i < N / 4; i++) {
            if (nums[i] == nums[N / 4 + i])
                return nums[i];
            if (nums[N / 4 + i] == nums[2 * N / 4 + i])
                return nums[N / 4 + i];
            if (nums[2 * N / 4 + i] == nums[3 * N / 4 + i])
                return nums[2 * N / 4 + i];
            if (nums[i] == nums[2 * N / 4 + i])
                return nums[i];
            if (nums[N / 4 + i] == nums[3 * N / 4 + i])
                return nums[N / 4 + i];
            if (nums[i] == nums[3 * N / 4 + i])
                return nums[i];
        }
        return -1;
    }
};

int main(void) {
    Solution s;
}
