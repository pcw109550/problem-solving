// 279. Perfect Squares
#include <algorithm>
#include <iostream>
#include <cmath>
#include <vector>

class Solution {
    public:
        int numSquares(int n) {
            // O(N ** 2)
            static std::vector<int> D ({0});
            while (D.size() <= n) {
                int temp = 1 << 30;
                for (int j = 1; j * j <= D.size(); j++) {
                    temp = std::min(temp, D[D.size() - j * j] + 1);
                }
                D.emplace_back(temp);
            }
            return D[n];
        }
};

class Solution2 {
    public:
        int numSquares(int n) {
            // O(N ** 2)
            std::vector<int> D (n + 1, 1 << 30);
            D[0] = 0;
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j * j <= i; j++) {
                    D[i] = std::min(D[i], D[i - j * j] + 1);
                }
            }
            return D[n];
        }
};

int main(void) {
    Solution s;
    int result = s.numSquares(1234124);
    std::cout << result;
}