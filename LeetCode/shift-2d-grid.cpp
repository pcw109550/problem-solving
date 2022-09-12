#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        // O(M * N)
        int M = grid.size(), N = grid[0].size();
        vector<vector<int> > result (M, vector<int>(N));
        for (int i = 0; i < M * N; i++) {
            int cur = ((i - k) % (M * N) + M * N) % (M * N);
            result[i / N][i % N] = grid[cur / N][cur % N];
        }
        return result;
    }
};