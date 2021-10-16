// 309. Best Time to Buy and Sell Stock with Cooldown
#include <algorithm>
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // O(N)
        int N = prices.size();
        int result = 0;
        vector<vector<int> > D (N, vector<int>(3, INT_MIN));
        D[0][0] = D[0][1] = D[0][2] = 0;
        for (int i = 1; i < N; i++) {
            // buy
            for (int j = 0; j < i; j++) {
                D[i][0] = max(D[i][0], D[j][2]); // cooldown
                if (j >= 1)
                    D[i][0] = max(D[i][0], D[j - 1][1]); // sell
            }
            // sell
            for (int j = 0; j < i; j++) {
                D[i][1] = max(D[i][1], D[j][0] + prices[i] - prices[j]); // buy
            }
            // cooldown
            for (int j = 0; j < i; j++) {
                D[i][2] = max(D[i][2], D[j][0]); // buy
                D[i][2] = max(D[i][2], D[j][1]); // sell
                D[i][2] = max(D[i][2], D[j][2]); // cooldown
            }
            result = max(result, D[i][0]);
            result = max(result, D[i][1]);
            result = max(result, D[i][2]);
        }
        return result;
    }
};

int main(void) {
    Solution s;
}