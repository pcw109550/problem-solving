#include <algorithm>
#include <iostream>
#include <vector>
#include <climits>
#include <utility>
using namespace std;
#define FIELD 1000000007

class Solution {
public:
    int maxProductPath(vector<vector<int>>& grid) {
        // O(M * N)
        int M = grid.size(), N = grid[0].size();
        vector<vector<pair<long long, long long> > > D(M, vector<pair<long long, long long> > (N, {0, 0}));
        for (int i = 0; i < M; i++) 
            for (int j = 0; j < N; j++) {
                if (i == 0 && j == 0) {
                    D[0][0] = {grid[0][0], grid[0][0]};
                    continue;
                }
                long long cur = grid[i][j];
                long long Min = LLONG_MAX;
                long long Max = LLONG_MIN;
                if (i >= 1) {
                    auto u = D[i - 1][j];
                    Min = min(Min, min(u.first * cur, u.second * cur));
                    Max = max(Max, max(u.first * cur, u.second * cur));
                }
                if (j >= 1) {
                    auto v = D[i][j - 1];
                    Min = min(Min, min(v.first * cur, v.second * cur));
                    Max = max(Max, max(v.first * cur, v.second * cur));
                }
                D[i][j].first = Min;
                D[i][j].second = Max;
            }
        long long result = D[M - 1][N - 1].second;
        return result >= 0 ? result % FIELD : -1;
    }
};