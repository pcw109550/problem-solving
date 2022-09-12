#include <algorithm>
#include <iostream>
#include <vector>
#include <climits>
#include <cmath>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        // O(M * N * log(M * N))
        int result = 0;
        int M = grid.size(), N = grid[0].size();
        int K = M * N;
        unordered_set<int> S;
        vector<int> D;
        for (int i = 0; i < M; i++)
            for (int j = 0; j < N; j++) {
                S.insert(grid[i][j] % x);
                if (S.size() > 1)
                    return -1;
                D.push_back(grid[i][j]);
            }
        sort(D.begin(), D.end());
        int target;
        if (K % 2)
            target = D[(K - 1) / 2];
        else
            target = min(D[(K - 1) / 2], D[(K - 1) / 2 + 1]);
        for (int i = 0; i < K; i++)
            result += abs(D[i] - target) / x;
        return result;
    }
};