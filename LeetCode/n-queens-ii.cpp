// 52. N-Queens II
#include <iostream>
#include <vector>

class Solution {
    int N;
    int result;
    std::vector<bool> isused1, isused2, isused3;
    public:
        int totalNQueens(int n) {
            // O(N!)
            N = n;
            result = 0;
            isused1.resize(2 * n - 1, false);
            isused2.resize(2 * n - 1, false);
            isused3.resize(n, false);
            backtrack(0);
            return result;
        }

        void backtrack(int y) {
            if (y == N) {
                result++;
                return;
            }
            for (int x = 0; x < N; x++) {
                if (isused1[x + y] || isused2[x - y + N - 1] || isused3[x])
                    continue;
                isused1[x + y] = isused2[x - y + N - 1] = isused3[x] = true;
                backtrack(y + 1);
                isused1[x + y] = isused2[x - y + N - 1] = isused3[x] = false;
            }
        }
};

int main(void) {
    Solution s;
    std::cout << s.totalNQueens(100);
}