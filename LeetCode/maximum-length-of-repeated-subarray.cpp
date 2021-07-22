// 718. Maximum Length of Repeated Subarray
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:
        int findLength(vector<int>& nums1, vector<int>& nums2) {
            // O(M * N)
            int result = 0;
            int M = nums1.size();
            int N = nums2.size();
            vector<vector<int> > D (M, vector<int> (N, 0));
            for (int i = 0; i < M; i++)
                for (int j = 0; j < N; j++)
                    if (nums1[i] == nums2[j]) {
                        D[i][j] = i >= 1 && j >= 1 ? D[i - 1][j - 1] + 1 : 1; 
                        result = max(result, D[i][j]);
                    }
            return result;
        }
};

int main(void) {
    Solution s;
}