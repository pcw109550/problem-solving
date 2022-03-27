// 2022. Convert 1D Array Into 2D Array
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        // O(M * N)
        vector<vector<int> > result;
        int K = original.size();
        if (m * n != K)
            return result;
        for (int i = 0; i < m; i++) {
            vector<int> cur;
            for (int j = 0; j < n; j++)
                cur.push_back(original[n * i + j]);
            result.push_back(cur);
        }
        return result;
    }
};

int main(void) {
    Solution s;
}
