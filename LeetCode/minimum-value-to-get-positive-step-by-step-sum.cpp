// 1413. Minimum Value to Get Positive Step by Step Sum
#include <algorithm>
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int minStartValue(vector<int>& nums) {
        // O(N)
        int result = 0, Min = INT_MAX, temp = 0;
        int N = nums.size();
        for (auto num : nums) {
            temp += num;
            Min = min(Min, temp);
        }
        result = max(1, -Min + 1);
        return result;
    }
};

int main(void) {
    Solution s;
}