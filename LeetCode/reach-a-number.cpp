#include <iostream>
#include <climits>
using namespace std;

class Solution {
public:
    int reachNumber(int target) {
        // O(log(N))
        // target == a - b
        // result * (result + 1) / 2 == a + b
        // min(result) ?
        int lo = 1, hi = 60000;
        int mid;
        if (target < 0)
            target = -target;
        while (lo < hi) {
            mid = lo + (hi - lo) / 2;
            int temp = mid * (mid + 1) / 2 - target;
            if (temp < 0) {
                lo = mid + 1;
            } else
                hi = mid;
        }
        int result = mid;
        // O(1)
        while (true) {
            int temp = result * (result + 1) / 2 - target;
            if (temp % 2 == 0 && temp >= 0)
                break;
            result++;
        }
        return result;
    }
};