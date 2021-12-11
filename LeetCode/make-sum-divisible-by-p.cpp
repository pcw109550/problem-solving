// 1590. Make Sum Divisible by P
#include <algorithm>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <climits>
using namespace std;

class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        // O(N)
        int N = nums.size();
        int sum = 0;
        for (int i = 0; i < N; i++)
            sum = (sum + nums[i]) % p;
        if (sum == 0)
            return 0;
        int result = INT_MAX;
        unordered_map<int, int> M;
        int temp = 0;
        for (int i = 0; i < N; i++) {
            temp = (temp + nums[i]) % p;
            int target = (temp - sum + p) % p;
            if (target == 0)
                result = min(result, i + 1);
            if (M.count(target))
                result = min(result, i - M[target]);
            M[temp] = i;
        }
        if (result == INT_MAX || result == N)
            return -1;
        return result;
    }
};

int main(void) {
    Solution s;
}