// 688. Knight Probability in Chessboard
#include <iostream>
#include <vector>
using namespace std;
int dx[8] = {2, 2, 1, 1, -1, -1, -2, -2};
int dy[8] = {1, -1, 2, -2, 2, -2, 1, -1};

class Solution {
    public:
        double knightProbability(int n, int k, int row, int column) {
            // O(N ** 2 * K)
            double result = 0.0;
            vector<vector<double> > D (n, vector<double>(n, 0));
            D[row][column] = 1;
            for (int trial = 0; trial < k; trial++) {
                vector<vector<double> > temp (n, vector<double>(n, 0));
                for (int i = 0; i < n; i++)
                    for (int j = 0; j < n; j++)
                        for (int dir = 0; dir < 8; dir++) {
                            int x = i + dx[dir];
                            int y = j + dy[dir];
                            if (x < 0 || y < 0 || x >= n || y >= n)
                                continue;
                            temp[x][y] += D[i][j] / 8;
                        }
                D = temp;
            }
            for (int i = 0; i < n; i++)
                for (int j = 0; j < n; j++)
                    result += D[i][j];
            return result;
        }
};

int main(void) {
    Solution s;
}