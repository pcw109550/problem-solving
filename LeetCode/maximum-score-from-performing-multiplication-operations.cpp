// 1770. Maximum Score from Performing Multiplication Operations
#include <algorithm>
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        // O(M ** 2)
        int result = INT_MIN;
        int N = nums.size(), M = multipliers.size();
        vector<vector<int> > D (M + 1, vector<int> (M + 1)); // D[i][j]: left i, right j consumed
        D[0][0] = 0;
        for (int i = 0; i < M; i++) {
            for (int j = 0; j <= i + 1; j++) {
                int a = INT_MIN, b = INT_MIN;
                if (j - 1 >= 0)
                    a = D[j - 1][i + 1 - j] + multipliers[i] * nums[j - 1];
                if (i + 1 - j - 1 >= 0)
                    b = D[j][i + 1 - j - 1] + multipliers[i] * nums[N - 1 - (i - j)];
                D[j][i + 1 - j] = max(a, b);
            }
        }
        for (int i = 0; i <= M; i++)
            result = max(result, D[i][M - i]);
        return result;
    }
};

int main(void) {
    Solution s;
}