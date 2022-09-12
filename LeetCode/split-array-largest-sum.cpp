#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
#define MAX 1000000000

class Solution {
public:
    // Defined it as per the maximum size of array and split count
    // But can be defined with the input size as well
    int memo[1001][51];
    
    int getMinimumLargestSplitSum(vector<int>& prefixSum, int currIndex, int subarrayCount) {
        int n = prefixSum.size() - 1;
        
        // We have already calculated the answer so no need to go into recursion
        if (memo[currIndex][subarrayCount] != -1) {
            return memo[currIndex][subarrayCount];
        }
        
        // Base Case: If there is only one subarray left, then all of the remaining numbers
        // must go in the current subarray. So return the sum of the remaining numbers.
        if (subarrayCount == 1) {
            return memo[currIndex][subarrayCount] = prefixSum[n] - prefixSum[currIndex];
        }
        
        // Otherwise, use the recurrence relation to determine the minimum largest subarray
        // sum between currIndex and the end of the array with subarrayCount subarrays remaining.
        int minimumLargestSplitSum = INT_MAX;
        for (int i = currIndex; i <= n - subarrayCount; i++) {
            // Store the sum of the first subarray.
            int firstSplitSum = prefixSum[i + 1] - prefixSum[currIndex];
            
            // Find the maximum subarray sum for the current first split.
            int largestSplitSum = max(firstSplitSum, 
                                      getMinimumLargestSplitSum(prefixSum, i + 1, subarrayCount - 1));
            
            // Find the minimum among all possible combinations.
            minimumLargestSplitSum = min(minimumLargestSplitSum, largestSplitSum);
             
            if (firstSplitSum >= minimumLargestSplitSum) {
                break;
            }
        }
        
        return memo[currIndex][subarrayCount] = minimumLargestSplitSum;
    }
                       
    int splitArray(vector<int>& nums, int m) {
        // Marking all values to -1 so that we can differentiate 
        // If we have already calculated the answer or not
        memset(memo, -1, sizeof(memo));
        
        // Store the prefix sum of nums array.
        int n = nums.size();
        vector<int> prefixSum(n + 1, 0);
        for (int i = 0; i < n; i++) {
            prefixSum[i + 1] = prefixSum[i] + nums[i];
        }
        
        return getMinimumLargestSplitSum(prefixSum, 0, m);
    }
};

class Solution2 {
public:
    int splitArray(vector<int>& nums, int M) {
        // WRONG
        // O(N ** 2 * M)
        int result = 0;
        int N = nums.size();
        vector<vector<vector<vector<int> > > > D(N, vector<vector<vector<int>> > (N, vector<vector<int>>(M, vector<int>(3, MAX))));
        vector<int> A(N + 1, 0);
        for (int i = 0; i < N; i++)
            A[i + 1] = A[i] + nums[i];
        
        for (int l = 1; l <= N; l++)
            for (int i = 0; i <= N - l; i++)
                D[i][i + l - 1][0][0] = D[i][i + l - 1][0][1] = D[i][i + l - 1][0][2] = A[i + l] - A[i];
            

        for (int k = 1; k < M; k++) {
            for (int l = 1; l <= N; l++) {
                for (int i = 0; i <= N - l; i++) {
                    int j = i + l - 1;
                    int temp, cur = MAX, l, r;
                    if (i + 1 < N) {
                        temp = max(nums[i], D[i + 1][j][k - 1][2]);
                        if (cur > temp) {
                            cur = temp;
                            l = nums[i];
                            r = D[i + 1][j][k - 1][1];
                        }
                    }
                    if (j - 1 >= 0) {
                        temp = max(nums[j], D[i][j - 1][k - 1][2]);
                        if (cur > temp) {
                            cur = temp;
                            l = D[i][j - 1][k - 1][0];
                            r = nums[j];
                        }
                    }
                    if (i + 1 < N) {
                        temp = max(nums[i] + D[i + 1][j][k][0], D[i + 1][j][k][2]);
                        if (cur > temp) {
                            cur = temp;
                            l = nums[i] + D[i + 1][j][k][0];
                            r = D[i + 1][j][k][1];
                        }
                    }
                    if (j - 1 >= 0) {
                        temp = max(D[i][j - 1][k][1] + nums[j], D[i][j - 1][k][2]);
                        if (cur > temp) {
                            cur = temp;
                            l = D[i][j - 1][k][0];
                            r = D[i][j - 1][k][1] + nums[j];
                        }
                    }
                    D[i][j][k][0] = l;
                    D[i][j][k][1] = r;
                    D[i][j][k][2] = cur;
                }   
            }        
        }
        
        result = D[0][N - 1][M - 1][2];
        return result;
    }
};