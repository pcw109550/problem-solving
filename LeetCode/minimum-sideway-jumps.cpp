// 1824. Minimum Sideway Jumps
#include <algorithm>
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int minSideJumps(vector<int>& obstacles) {
        // O(N)
        int result = 0;
        int N = obstacles.size();
        vector<vector<int> > D(N, vector<int>(3, -2));
        D[0][0] = D[0][2] = 1; D[0][1] = 0;
        for (int i = 1; i < N; i++) {
            if (obstacles[i] != 0) 
                D[i][obstacles[i] - 1] = -1;
            int Min = INT_MAX;
            for (int j = 0; j < 3; j++)
                if (D[i - 1][j] >= 0 && D[i][j] != -1) {
                    D[i][j] = D[i - 1][j];
                    Min = min(Min, D[i][j]);
                }
            for (int j = 0; j < 3; j++)
                if (D[i][j] == -2)
                    D[i][j] = Min + 1;
        }
        result = *min_element(D[N - 1].begin(), D[N - 1].end());
        return result;
    }
};

int main(void) {
    Solution s;
}