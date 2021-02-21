// 413. Arithmetic Slices
#include <iostream>
#include <vector>

class Solution {
    public:
        int numberOfArithmeticSlices(std::vector<int>& A) {
            // O(N)
            int result = 0;
            int N = A.size();
            if (N < 3)
                return result;
            int length = 2, d = A[1] - A[0], curr_d;
            for (int i = 1; i < N - 1; i++) {
                curr_d = A[i + 1] - A[i];
                if (curr_d == d)
                    length++;
                else {
                    result += (length - 1) * (length - 2) / 2;
                    length = 2;
                    d = curr_d;                    
                }
            }
            result += (length - 1) * (length - 2) / 2;
            return result;
        }
};

int main(void) {
    Solution s;
}