#include <algorithm>
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        // O(M * N ** 2 * K)
        int result = INT_MAX;
        vector<vector<vector<int> > > D(m + 1, vector<vector<int> >(n + 1, vector<int>(target + 1, INT_MAX)));
        for (int i = 1; i <= m; i++) {
            // not colored
            if (houses[i - 1] == 0) {
                for (int k = 1; k <= target; k++) {
                    for (int j = 1; j <= n; j++) {
                        int temp = INT_MAX;
                        for (int l = 1; l <= n; l++) {
                            int cur = D[i - 1][l][k - (j != l)];
                            if (i == 1 && (k - (j != l) == 0))
                                cur = 0;
                            temp = min(temp, cur);
                        }
                        if (temp != INT_MAX)
                            temp += cost[i - 1][j - 1];
                        D[i][j][k] = temp;
                    }
                }
            } else {
                // colored
                int color = houses[i - 1];
                // only need to update D[i][color][k]
                for (int k = 1; k <= target; k++) {
                    int temp = INT_MAX;
                    for (int j = 1; j <= n; j++) {
                        int cur = D[i - 1][j][k - (j != color)];
                        if (i == 1 && k - (j != color) == 0)
                            cur = 0;
                        temp = min(temp, cur);
                    }
                    // no cost
                    D[i][color][k] = temp;
                }
            }
        }
        for (int i = 1; i <= n; i++)
            result = min(result, D[m][i][target]);
        return result == INT_MAX ? -1 : result;
    }
};