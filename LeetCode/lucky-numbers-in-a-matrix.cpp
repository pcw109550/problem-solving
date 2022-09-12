#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        // O(M * N)
        vector<int> result;
        int M = matrix.size(), N = matrix[0].size();
        vector<int> colMax;
        for (int i = 0; i < N; i++) {
            int Max = -1;
            for (int j = 0; j < M; j++)
                Max = max(Max, matrix[j][i]);
            colMax.push_back(Max);
        }
        for (int i = 0; i < M; i++) {
            auto it = min_element(matrix[i].begin(), matrix[i].end());
            int pos = it - matrix[i].begin();
            if (colMax[pos] == *it)
                result.push_back(*it);
        }
        return result;
    }
};