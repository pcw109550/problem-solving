#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
#define FIELD 1000000007

class Solution {
public:
    int numRollsToTarget(int N, int K, int target) {
        // O(N * M * K)
        vector<vector<int> > D(N + 1, vector<int>(target + 1, 0));
        for (int k = 1; k <= min(K, target); k++)
            D[1][k] = 1;
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= target; j++) {
                for (int k = 1; k <= K; k++) {
                    if (j < k)
                        continue;
                    D[i][j] = (D[i][j] + D[i - 1][j - k]) % FIELD;
                }
            }
        }
        return D[N][target];
    }
};