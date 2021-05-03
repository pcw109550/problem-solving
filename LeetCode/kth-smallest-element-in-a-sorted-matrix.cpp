// 378. Kth Smallest Element in a Sorted Matrix
#include <iostream>
#include <vector>
#include <queue>

class Solution {
    public:
        int kthSmallest(std::vector<std::vector<int> >& matrix, int k) {
            // O(M * N * log(K))
            std::priority_queue<int> Q;
            int M = matrix.size(), N = matrix[0].size();
            for (int i = 0; i < M; i++)
                for (int j = 0; j < N; j++) {
                    Q.push(matrix[i][j]);
                    if (Q.size() > k)
                        Q.pop();
                }
            return Q.top();
        }
};

int main(void) {
    Solution s;
}