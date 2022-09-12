#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        // O(N ** 2)
        int N = nums.size();
        int result = 0;
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                if (i != j)
                    result = max(result, (nums[i] - 1) * (nums[j] - 1));
        return result;
    }
};