// 668. Kth Smallest Number in Multiplication Table
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
    public:
        int findKthNumber(int m, int n, int k) {
            // O(M * log(M * N))
            int result = 0;
            int lo = 1, hi = m * n, mid;
            while (lo < hi) {
                mid = lo + (hi - lo) / 2;
                int cnt = count(mid, m, n);
                if (cnt < k)
                    lo = mid + 1;
                else
                    hi = mid;
            }
            return lo;
        }
    
        int count (int t, int m, int n) {
            int result = 0;
            for (int i = 1; i <= m; i++)
                result += min(n, t / i);
            return result;
        }
};

int main(void) {
    Solution s;
}