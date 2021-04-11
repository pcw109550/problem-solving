// 775. Global and Local Inversions
#include <algorithm>
#include <iostream>
#include <vector>
#include <utility>

class Solution {
    public:
        bool isIdealPermutation(std::vector<int>& A) {
            // O(N)
            int N = A.size();
            for (int i = 0; i < N; i++)
                if (i - A[i] > 1 || i - A[i] < -1)
                    return false;
            return true;
        }
};

int main(void) {
    Solution s;
}