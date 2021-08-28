// 416. Partition Equal Subset Sum
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        // O(N * M)
        bool result = true;
        int N = nums.size();
        int sum = 0;
        for (auto num : nums)
            sum += num;
        if (sum % 2 == 1)
            return false;
        // D[i][j] : possiblity of using until ith number to add up to j
        vector<vector<bool> > D (N + 1, vector<bool>(sum / 2 + 1, false));
        for (int i = 0; i <= N; i++)
            D[i][0] = true;
        for (int j = 1; j <= sum / 2; j++)
            for (int i = 1; i <= N; i++) {
                D[i][j] = (j >= nums[i - 1]) ? D[i - 1][j - nums[i - 1]] : false;
                D[i][j] = D[i][j] || D[i - 1][j];
            }
        result = D[N - 1][sum / 2];
        return result;
    }
};

int main(void){
    Solution s;
}