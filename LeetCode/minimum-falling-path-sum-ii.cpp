#include <algorithm>
#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        // O(N ** 2 * log(N))
        int N = grid.size();
        int result = 0;
        vector<vector<int> > D(N, vector<int>(N, 0));
        multiset<int> S, S_prev;
        for (int i = 0; i < N; i++) {
            D[0][i] = grid[0][i];
            S_prev.insert(grid[0][i]);
        }
        for (int i = 1; i < N; i++) {
            S.clear();
            for (int j = 0; j < N; j++) {
                auto b = S_prev.find(D[i - 1][j]);
                int store = *b;
                S_prev.erase(b);
                D[i][j] = grid[i][j] + *S_prev.begin();
                S.insert(D[i][j]);
                S_prev.insert(store);
            }
            S_prev = S;
        }
        result = *min_element(D[N - 1].begin(), D[N - 1].end());
        return result;
    }
};