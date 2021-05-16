// 1423. Maximum Points You Can Obtain from Cards
#include <algorithm>
#include <iostream>
#include <vector>

class Solution {
    public:
        int maxScore(std::vector<int>& cardPoints, int k) {
            // O(N)
            int result = 0;
            int N = cardPoints.size();
            std::vector<int> A (N + 1, 0);
            std::vector<int> B (N + 1, 0);
            for (int i = 0; i < N; i++) {
                A[i + 1] = A[i] + cardPoints[i];
                B[N - i - 1] = B[N - i] + cardPoints[N - i - 1];
            }
            for (int i = 0; i <= k; i++) {
                int temp = A[i] + B[N - k + i];
                result = std::max(result, temp);
            }
            return result;
        }
};

int main(void) {
    Solution s;
}