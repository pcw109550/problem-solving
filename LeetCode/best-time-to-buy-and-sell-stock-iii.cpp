// 123. Best Time to Buy and Sell Stock III
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // O(N)
        int result = 0;
        int N = prices.size();
        vector<int> D1(N, 0);
        int Min = prices[0];
        for (int i = 1; i < N; i++) {
            D1[i] = max(0, prices[i] - Min);
            Min = min(Min, prices[i]);
        }
        vector<int> D2(N, 0);
        int Max = prices[N - 1];
        for (int i = N - 2; i >= 0; i--) {
            D2[i] = max(D2[i + 1], Max - prices[i]);
            Max = max(Max, prices[i]);
        }
        for (int i = 0; i < N; i++)
            result = max(result, D1[i] + (i + 1 < N ? D2[i + 1] : 0));
        return result;
    }
};

int main(void) {
    Solution s;
}