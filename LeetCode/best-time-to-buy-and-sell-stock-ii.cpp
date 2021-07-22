// 122. Best Time to Buy and Sell Stock II
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:
        int maxProfit(vector<int>& prices) {
            // O(N)
            int result = 0;
            for (int i = 0; i < prices.size() - 1; i++)
                if (prices[i] < prices[i + 1])
                    result += prices[i + 1] - prices[i];
            return result;
        }
};

int main(void) {
    Solution s;
}