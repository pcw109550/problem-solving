#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int largest1BorderedSquare(vector<vector<int>>& grid) {
        // O(N * M ** 2)
        int result = 0;
        int M = grid.size(), N = grid[0].size();
        vector<vector<int> > D(M + 1, vector<int> (N + 1, 0));
        for (int i = 0; i < M; i++)
            for (int j = 0; j < N; j++)
                D[i + 1][j + 1] = grid[i][j] + D[i][j + 1] + D[i + 1][j] - D[i][j];
        if (D[M][N])
            result = 1;
        for (int i = 1; i <= M; i++) {
            for (int j = 1; j <= N; j++) {
                for (int k = min(i, j); k >= 1; k--) {
                    int outer = D[i][j] - D[i - k][j] - D[i][j - k] + D[i - k][j - k];
                    if (k == 1 && outer == 1 * 1) {
                        result = max(result, 1 * 1);
                        break;
                    } else if (k == 2 && outer == 2 * 2) {
                        result = max(result, 2 * 2);
                        break;  
                    } else if (k >= 3) {
                        int inner = D[i - 1][j - 1] - D[i - k + 1][j - 1] - D[i - 1][j - k + 1] + D[i - k + 1][j - k + 1]; 
                        if (outer - inner == k * k - (k - 2) * (k - 2)) {
                            result = max(result, k * k);
                            break;
                        }
                    }
                }
            }
        }
        return result;
    }
};