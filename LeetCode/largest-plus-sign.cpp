// 764. Largest Plus Sign
#include <algorithm>
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int orderOfLargestPlusSign(int n, vector<vector<int>>& mines) {
        // O(N ** 2)
        int result = 0;
        vector<vector<int> > M (n, vector<int>(n, 1));
        for (auto mine : mines)
            M[mine[0]][mine[1]] = 0;
        vector<vector<vector<int> > > L (4, vector<vector<int> >(n, vector<int>(n, 0)));
        for (int i = 0; i < n; i++) {
            int len = 0;
            for (int j = 0; j < n; j++) {
                if (M[i][j] == 1)
                    len++;
                else
                    len = 0;
                L[0][i][j] = len;
            }
        }
        for (int i = 0; i < n; i++) {
            int len = 0;
            for (int j = n - 1; j >= 0; j--) {
                if (M[i][j] == 1)
                    len++;
                else
                    len = 0;
                L[1][i][j] = len;
            }
        }
        for (int j = 0; j < n; j++) {
            int len = 0;
            for (int i = 0; i < n; i++) {
                if (M[i][j] == 1)
                    len++;
                else
                    len = 0;
                L[2][i][j] = len;
            }
        } 
        for (int j = 0; j < n; j++) {
            int len = 0;
            for (int i = n - 1; i >= 0; i--) {
                if (M[i][j] == 1)
                    len++;
                else
                    len = 0;
                L[3][i][j] = len;
            }
        } 
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int temp_result = INT_MAX;
                for (int k = 0; k < 4; k++)
                    temp_result = min(temp_result, L[k][i][j]);
                result = max(result, temp_result);
            }
        }
        return result;
    }
};

int main(void) {
    Solution s;
}