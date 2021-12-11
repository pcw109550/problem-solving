// 867. Transpose Matrix
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        // O(M * N)
        int M = matrix.size(), N = matrix[0].size();
        vector<vector<int> > result (N, vector<int>(M));
        for (int i = 0; i < M; i++)
            for (int j = 0; j < N; j++) 
                result[j][i] = matrix[i][j];
        return result;
    }
};

int main(void) {
    Solution s;
}