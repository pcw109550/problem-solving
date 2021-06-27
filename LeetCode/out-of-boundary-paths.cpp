// 576. Out of Boundary Paths
#include <iostream>
#include <vector>
using namespace std;
#define FIELD 1000000007
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

class Solution {
    public:
        int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
            // O(M * N * K)
            int result = 0;
            vector<vector<int> > D (m, vector<int> (n, 0));
            D[startRow][startColumn] = 1;
            for (int trial = 0; trial < maxMove; trial++) {
                vector<vector<int> > temp (m, vector<int> (n, 0));
                for (int i = 0; i < m; i++)
                    for (int j = 0; j < n; j++) {
                        int val = 0;
                        for (int dir = 0; dir < 4; dir++) {
                            int x = i + dx[dir];
                            int y = j + dy[dir];
                            if (x < 0 || y < 0 || x >= m || y >= n) {
                                result += D[i][j];
                                result %= FIELD;
                                continue;
                            }
                            val += D[x][y];
                            val %= FIELD;
                        }
                        temp[i][j] = val;
                    }
                D = temp;
            }
            return result;
        }
};

int main(void) {
    Solution s;
}