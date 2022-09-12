#include <algorithm>
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        // O(M * N * log(N))
        int result = 0;
        int M = matrix.size(), N = matrix[0].size();
        vector<vector<int> > D1 (M, vector<int> (N, 0));
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++)
                D1[i][j] = matrix[i][j] * (matrix[i][j] + (i >= 1 ? D1[i - 1][j] : 0));
            auto temp = D1[i];
            sort(temp.begin(), temp.end(), greater<int>());
            for (int j = 0; j < N; j++)
                result = max(result, (j + 1) * temp[j]);
        }
        return result;
    }
};