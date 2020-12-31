// 1492. The kth Factor of n
#include <iostream>
#include <vector>

class Solution {
    public:
        int kthFactor(int n, int k) {
            // O(sqrt(N))
            std::vector<int> factor_1;
            std::vector<int> factor_2;
            int result = -1;
            for (int i = 1; i * i <= n; i++) {
                if (n % i == 0) {
                    factor_1.emplace_back(i);
                    if (i * i != n)
                        factor_2.emplace_back(n / i);
                }
            }
            if (factor_1.size() + factor_2.size() < k)
                return result;
            if (factor_1.size() >= k)
                result = factor_1[k - 1];
            else
                result = factor_2[factor_2.size() - (k - factor_1.size())];
            return result;
        }
};

int main(void) {
    Solution s;
}