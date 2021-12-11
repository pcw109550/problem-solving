// 650. 2 Keys Keyboard
#include <algorithm>
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int minSteps(int n) {
        // O(N ** 2)
        int result = INT_MAX;
        vector<vector<int> > D(n + 1, vector<int>(n + 1, -1));
        // State: {# of "A"s printed, # of "A"s copied}
        D[1][0] = 0;
        for (int i = 1; i <= n; i++) {
            int cur_min = INT_MAX;
            for (int j = 1; j <= i; j++) {
                if (i != j) {
                    if (D[i - j][j] != -1) {
                        D[i][j] = D[i - j][j] + 1;
                        cur_min = min(cur_min, D[i][j]);
                    }
                } else
                    D[i][j] = 1 + (cur_min == INT_MAX ? 0 : cur_min);
            }
        }
        for (int i = 0; i <= n; i++)
            if (D[n][i] != -1)
                result = min(result, D[n][i]);
        return result;
    }
};

int main(void) {
    Solution s;
}