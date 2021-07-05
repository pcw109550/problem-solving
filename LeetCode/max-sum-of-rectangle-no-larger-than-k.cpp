// 363. Max Sum of Rectangle No Larger Than K
#include <algorithm>
#include <iostream>
#include <vector>
#include <climits>
#include <set>
using namespace std;

class Solution {
    public:
        int result = INT_MIN;
    
        void updateResult(vector<int>& nums, int k) {
            int sum = 0;

            // Container to store sorted prefix sums.
            set<int> sortedSum;
            set<int>::iterator it;

            // Add 0 as the prefix sum for an empty sub-array.
            sortedSum.insert(0);
            for (int& num : nums) {
                // Running Sum.
                sum += num;

                // Get X where Running sum - X <= k such that sum - X is closest to k.
                it = sortedSum.lower_bound(sum - k);

                // If such X is found in the prefix sums.
                // Get the sum of that sub array and update the global maximum resul.
                if (it != sortedSum.end())
                    result = max(result, sum - *it);

                // Insert the current running sum to the prefix sums container.
                sortedSum.insert(sum);
            }
        }
    
        int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
            // O(M ** 2 * N * log(N))
            // Stores the 1D representation of the matrix.
            vector<int> rowSum(matrix[0].size());
            for (int i = 0; i < matrix.size(); i++) {
                // Initialize the 1D representation with 0s.
                fill(rowSum.begin(), rowSum.end(), 0);

                // We convert the matrix between rows i..row inclusive to 1D array
                for (int row = i; row < matrix.size(); row++) {
                    // Add the current row to the previous row.
                    // This converts the matrix between i..row to 1D array
                    for (int col = 0; col < matrix[0].size(); col++)
                        rowSum[col] += matrix[row][col];

                    // Run the 1D algorithm for `rowSum`
                    updateResult(rowSum, k);

                    // If result is k, this is the best possible answer, so return.
                    if (result == k)
                        return result;
                }
            }
            return result;
        }
};


class Solution2 {
    public:
        int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
            // O(M ** 2 * N ** 2)
            int result = INT_MIN;
            int M = matrix.size();
            int N = matrix[0].size();
            vector<vector<int> > D (M + 1, vector<int> (N + 1, 0));
            vector<int> temp;
            for (int i = 0; i < M; i++)
                for (int j = 0; j < N; j++)
                    D[i + 1][j + 1] = D[i][j + 1] + D[i + 1][j] - D[i][j] + matrix[i][j];
            for (int x1 = 0; x1 <= M; x1++)
                for (int x2 = x1 + 1; x2 <= M; x2++)
                    for (int y1 = 0; y1 <= N; y1++)
                        for (int y2 = y1 + 1; y2 <= N; y2++) {
                            int sum = D[x2][y2] - D[x1][y2] - D[x2][y1] + D[x1][y1];
                            if (sum <= k && result <= sum)
                                result = sum;
                        }
            return result;
        }
};

class Solution3 {
    public:
        int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
            // O(M ** 2 * N ** 2 * log(M * N))
            int result = 0;
            int M = matrix.size();
            int N = matrix[0].size();
            vector<vector<int> > D (M + 1, vector<int> (N + 1, 0));
            vector<int> temp;
            for (int i = 0; i < M; i++)
                for (int j = 0; j < N; j++)
                    D[i + 1][j + 1] = D[i][j + 1] + D[i + 1][j] - D[i][j] + matrix[i][j];
            for (int x1 = 0; x1 <= M; x1++)
                for (int x2 = x1 + 1; x2 <= M; x2++)
                    for (int y1 = 0; y1 <= N; y1++)
                        for (int y2 = y1 + 1; y2 <= N; y2++) {
                            int sum = D[x2][y2] - D[x1][y2] - D[x2][y1] + D[x1][y1];
                            temp.push_back(sum);
                        }
            sort(temp.begin(), temp.end());
            auto it = upper_bound(temp.begin(), temp.end(), k);
            result = *(--it);
            return result;
        }
};

int main(void) {
    Solution s;
}