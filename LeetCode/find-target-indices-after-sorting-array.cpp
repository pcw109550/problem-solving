// 2089. Find Target Indices After Sorting Array
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        // O(N * log(N))
        vector<int> result;
        int N = nums.size();
        sort(nums.begin(), nums.end());
        for (int i = 0; i < N; i++)
            if (nums[i] == target)
                result.push_back(i);
        return result;
    }
};

int main(void) {
    Solution s;
}
