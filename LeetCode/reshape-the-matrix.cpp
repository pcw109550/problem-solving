// 566. Reshape the Matrix
#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:
        vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
            // O(M * N)
            int M = mat.size();
            int N = mat[0].size();
            if (M * N != r * c)
                return mat;
            vector<vector<int> > result (r, vector<int> (c));
            int cnt = 0;
            for (int i = 0; i < M; i++)
                for (int j = 0; j < N; j++) {
                    result[cnt / c][cnt % c] = mat[i][j];
                    cnt++;
                }
            return result;
        }
};

int main(void) {
    Solution s;
}