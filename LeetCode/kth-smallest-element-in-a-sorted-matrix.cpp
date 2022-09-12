#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        // Time O(N * log(N) * log(M)) Space O(1)
        int N = matrix.size();
        int result = matrix[0][0];
        int lo = matrix[0][0], hi = matrix[N - 1][N - 1];
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            int cnt = N * N;
            for (int i = 0; i < N; i++) {
                auto it = upper_bound(matrix[i].begin(), matrix[i].end(), mid);
                cnt -= matrix[i].end() - it;
            }
            if (k <= cnt)
                hi = mid;
            else
                lo = mid + 1;
        }
        result = lo;
        return result;
    }
};