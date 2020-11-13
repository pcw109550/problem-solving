// 96. Unique Binary Search Trees
#include <iostream>

class Solution {
    public:
        int numTrees(int n) {
            // O(N)
            long long result = 1;
            for (int i = 0; i < n; i++)
                result = result * (2 * n - i) / (i + 1);
            result /= n + 1;
            return static_cast<int>(result);
        }
};

int main(void) {
    Solution s;
    int n = 5;
    std::cout << s.numTrees(n);
}