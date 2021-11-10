// 278. First Bad Version
#include <iostream>
using namespace std;
// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

bool isBadVersion(int mid) {
    return true;
}

class Solution {
public:
    int firstBadVersion(int n) {
        // O(log(N))
        int lo = 1, hi = n;
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (!isBadVersion(mid))
                lo = mid + 1;
            else 
                hi = mid;
        }
        return lo;
    }
};

int main(void) {
    Solution s;
}
