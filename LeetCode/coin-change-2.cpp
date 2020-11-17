// 518. Coin Change 2
#include <iostream>
#include <vector>

class Solution {
    public:
        int change(int amount, std::vector<int>& coins) {
            // O(M * N)
            if (coins.size() == 0)
                return amount == 0;
            int D[500][5001] = {};
            int num_coins = coins.size();
            for (int i = 0; i <= amount; i += coins[0])
                D[0][i] = 1;
            for (int i = 1; i < num_coins; i++) {
                for (int j = 0; j <= amount; j++) {
                    D[i][j] = D[i - 1][j];
                    if (j >= coins[i])
                        D[i][j] += D[i][j - coins[i]];
                }
            }
            return D[num_coins - 1][amount];
        }
};

int main(void) {
    Solution s;
    int amount = 5;
    std::vector<int> coins {1, 2, 5};
    std::cout << s.change(amount, coins);
}