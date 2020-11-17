// 845. Longest Mountain in Array
#include <algorithm>
#include <iostream>
#include <vector>

class Solution {
    public:
        int longestMountain(std::vector<int>& A) {
            // O(N)
            int N = A.size();
            int result = 0, base = 0;
            while (base < N) {
                int end = base;
                if (end + 1 < N && A[end] < A[end + 1]) {
                    while (end + 1 < N && A[end] < A[end + 1])
                        end++;
                    if (end + 1 < N && A[end] > A[end + 1]) {
                        while (end + 1 < N && A[end] > A[end + 1])
                            end++;
                        result = std::max(result, end - base + 1);
                    }
                }
                base = std::max(end, base + 1);
            }
            return result;
        }
};

int main(void) {
    Solution s;
    std::vector<int> A {2,1,4,7,3,2,5};
    std::cout << s.longestMountain(A);
}