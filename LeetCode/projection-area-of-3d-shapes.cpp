#include <algorithm>
#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

class Solution {
public:
    int projectionArea(vector<vector<int>>& grid) {
        // O(N ** 2)
        int N = grid.size();
        int result = 0;
        vector<int> x(N), y(N);
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                if (grid[i][j] > 0) {
                    result++;
                    x[i] = max(x[i], grid[i][j]);
                    y[j] = max(y[j], grid[i][j]);
                }
        result += accumulate(x.begin(), x.end(), 0);
        result += accumulate(y.begin(), y.end(), 0);
        return result;
    }
};