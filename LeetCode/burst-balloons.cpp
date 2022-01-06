// 312. Burst Balloons
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxCoins(vector<int>& nums) {
        // O(N ** 3)
        int result = 0;
        int N = nums.size();
        vector<vector<int> > D(N, vector<int>(N, 0));
        for (int a = 0; a < N; a++)
            for (int b = 0; b < N - a; b++) {
                int i = b, j = a + b;
                int cur = 0;
                int temp = 1;
                temp *= (i - 1 >= 0 ? nums[i - 1] : 1);
                temp *= (j + 1 <  N ? nums[j + 1] : 1);
                for (int k = i; k <= j; k++) {
                    int t = temp * nums[k];
                    t += (k - 1 >= 0 ? D[i][k - 1] : 0);
                    t += (k + 1 <  N ? D[k + 1][j] : 0);
                    cur = max(cur, t);
                }
                D[i][j] = cur;
                result = max(result, D[i][j]);
            }
        return result;
    }
};

int main(void) {
    Solution s;
}