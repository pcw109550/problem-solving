#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int triangularSum(vector<int>& nums) {
        // O(N ** 2)
        int N = nums.size();
        vector<int> curr = nums, next;
        for (int i = 0; i < N - 1; i++) {
            next.clear();
            for (int j = 0; j < curr.size() - 1; j++)
                next.push_back((curr[j] + curr[j + 1]) % 10);
            curr = next;
        }
        int result = curr[0];
        return result;
    }
};