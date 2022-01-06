// 930. Binary Subarrays With Sum
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        // O(N)
        int result = 0;
        unordered_map<int, int> M;
        int sum = 0;
        M[0] = 1;
        for (auto num : nums) {
            sum += num;
            result += M[sum - goal];
            M[sum]++;
        }
        return result;
    }
};

int main(void) {
    Solution s;
}