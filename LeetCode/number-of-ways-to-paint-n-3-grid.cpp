// 1411. Number of Ways to Paint N × 3 Grid
#include <iostream>
#define FIELD 1000000007

class Solution {
    public:
        int numOfWays(int n) {
            // O(N)
            long long a = 6, b = 6, a_next, b_next;
            while (--n) {
                a_next = (3 * a + 2 * b) % FIELD;
                b_next = (2 * a + 2 * b) % FIELD;
                a = a_next;
                b = b_next;
            }
            return static_cast<int>((a + b) % FIELD);
        }
};

int main(void) {
    Solution s;
    int n = 5000;
    std::cout << s.numOfWays(n);
}