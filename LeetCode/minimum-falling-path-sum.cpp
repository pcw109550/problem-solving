// 931. Minimum Falling Path Sum
#include <algorithm>
#include <iostream>
#include <vector>
#include <climits>
using namespace std;
int dy[3] = {1, 0, -1};

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        // O(N ** 2)
        int result = INT_MAX;
        int N = matrix.size();
        vector<vector<int> > D(N, vector<int>(N, INT_MAX));
        D[0] = matrix[0];
        for (int i = 1; i < N; i++)
            for (int j = 0; j < N; j++) {
                int Min = INT_MAX;
                for (int dir = 0; dir < 3; dir++) {
                    int X = i - 1;
                    int Y = j + dy[dir];
                    if (X < 0 || Y < 0 || X >= N || Y >= N)
                        continue;
                    Min = min(Min, D[X][Y]);
                }
                D[i][j] = min(D[i][j], Min + matrix[i][j]);
            }
        result = *min_element(D[N - 1].begin(), D[N - 1].end());
        return result;
    }
};

int main(void) {
    Solution s;
}