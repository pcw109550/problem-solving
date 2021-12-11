// 790. Domino and Tromino Tiling
#include <iostream>
#include <vector>
using namespace std;
#define FIELD 1000000007

class Solution {
public:
    int numTilings(int n) {
        // O(N)
        int result = 0;
        vector<int> a(n + 1), b(n + 1), c(n + 1);
        c[0] = c[1] = 1;
        for (int i = 2; i <= n; i++) {
            a[i] = (b[i - 1] + c[i - 2]) % FIELD;
            b[i] = (a[i - 1] + c[i - 2]) % FIELD;
            c[i] = (c[i - 1] + c[i - 2]) % FIELD;
            c[i] = (c[i] + a[i - 1]) % FIELD;
            c[i] = (c[i] + b[i - 1]) % FIELD;
        }
        result = c[n];
        return result;
    }
};

int main(void) {
    Solution s;
}
