// 121. Best Time to Buy and Sell Stock
#include <algorithm>
#include <iostream>
#include <vector>
#include <climits>

class Solution {
    public:
        int maxProfit(std::vector<int>& prices) {
            // O(N)
            int Min = INT_MAX, Max = INT_MIN;
            int result = 0;
            for (int i = 0; i < prices.size(); i++) {
                if (Min > prices[i]) {
                    Min = prices[i];   
                    Max = prices[i];
                }
                Max = std::max(Max, prices[i]);
                result = std::max(result, Max - Min);
            }
            return result;
        }
};

int main(void) {
    Solution s;
}