// 598. Range Addition II
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        // O(N)
        int result = 0;
        int N = ops.size();
        int x = m, y = n;
        for (int i = 0; i < N; i++) {
            x = min(x, ops[i][0]);
            y = min(y, ops[i][1]);
        }
        result = x * y;
        return result;
    }
};

int main(void) {
    Solution s;
}