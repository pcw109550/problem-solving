// 322. Coin Change
#include <algorithm>
#include <iostream>
#include <vector>

class Solution {
    public:
        int coinChange(std::vector<int>& coins, int amount) {
            // O(N * M)
            int D[100000] = {};
            std::fill(D + 1, D + 100000, amount + 1);
            for (int i = 1; i <= amount; i++) {
                for (int j = 0; j < coins.size(); j++) {
                    if (coins[j] <= i)
                        D[i] = std::min(D[i], D[i - coins[j]] + 1);
                }
            }
            return D[amount] > amount ? -1 : D[amount];
        }
};

int main(void) {
    Solution s;
    std::vector<int> coins {1, 2, 5};
    int amount = 11;
    int result = s.coinChange(coins, amount);
    std::cout << result;
}