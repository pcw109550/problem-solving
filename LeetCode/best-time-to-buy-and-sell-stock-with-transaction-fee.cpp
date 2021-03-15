// 714. Best Time to Buy and Sell Stock with Transaction Fee
#include <algorithm>
#include <iostream>
#include <vector>

class Solution {
    public:
        int maxProfit(std::vector<int>& prices, int fee) {
            // O(N)
            int result = 0, hold = -prices[0];
            for (int i = 1; i < prices.size(); i++) {
                result = std::max(result, hold + prices[i] - fee);
                hold = std::max(hold, result - prices[i]);
            }
            return result;
        }
};

int main(void) {
    Solution s;
}