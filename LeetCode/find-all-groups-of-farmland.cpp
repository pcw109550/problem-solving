// 1992. Find All Groups of Farmland
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        // O(M * N)
        vector<vector<int>> result;
        int M = land.size(), N = land[0].size();
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                if (land[i][j] == 0 || land[i][j] == 2)
                    continue;
                int k = i, l = j;
                while (k < M) {
                    if (land[k][j] == 1)
                        k++;
                    else
                        break;
                }
                while (l < N) {
                    if (land[i][l] == 1)
                        l++;
                    else
                        break;
                }
                result.push_back(vector<int> {i, j, k - 1, l - 1});
                for (int p = i; p < k; p++)
                    for (int q = j; q < l; q++)
                        land[p][q] = 2;
            }
        }
        return result;
    }
};

int main(void) {
    Solution s;
}