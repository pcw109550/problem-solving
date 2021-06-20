// 629. K Inverse Pairs Array
#include <algorithm>
#include <iostream>
#include <vector>
#define FIELD 1000000007

class Solution {
    public:
        int kInversePairs(int n, int k) {
            // O(N * K)
            int result = 0;
            k = std::min(k, n * (n - 1) / 2 - k);
            if (k < 0)
                return result;
            if (k == 0)
                return 1;
            std::vector<std::vector<int> > D (n + 1, std::vector<int>(1 + std::min(k, n * (n - 1) / 4), 0));
            D[1][0] = 1;
            for (int i = 2; i <= n; i++) {
                int acc = 0;
                int prev_size = 1 + (i - 1) * (i - 2) / 2;
                for (int j = 0; j <= std::min(k, i * (i - 1) / 4); j++) {
                    acc += D[i - 1][std::min(j, prev_size - 1 - j)];
                    acc %= FIELD;
                    if (j - i >= 0)
                        acc -= D[i - 1][j - i];
                    acc += FIELD;
                    acc %= FIELD;
                    D[i][j] = acc;
                }
            }
            result = D[n][k];
            return result;
        }
};

class Solution2 {
    public:
        int kInversePairs(int n, int k) {
            // O(N ** 3)
            int result = 0;
            k = std::min(k, n * (n - 1) / 2 - k);
            if (k < 0)
                return result;
            if (k == 0)
                return 1;
            std::vector<int> D (1 + n * (n - 1) / 4, 0);
            D[0] = 1;
            for (int i = 2; i <= n; i++) {
                std::vector<int> temp (1 + i * (i - 1) / 4, 0);
                int acc = 0;
                int prev_size = 1 + (i - 1) * (i - 2) / 2;
                for (int j = 0; j <= i * (i - 1) / 4; j++) {
                    acc += D[std::min(j, prev_size - 1 - j)];
                    acc %= FIELD;
                    if (j - i >= 0)
                        acc -= D[j - i];
                    acc %= FIELD;
                    acc += FIELD;
                    acc %= FIELD;
                    temp[j] = acc;
                }
                D = temp;
            }
            result = D[k];
            return result;
        }
};

// Note that k <= 1000
// D[n][k] = D[n - 1][k] + ... + D[n - 1][k - n + 1]
// D[n][k] = D[n][n * (n - 1) - k]

int main(void) {
    Solution s;
}