// 374. Guess Number Higher or Lower
#include <iostream>

/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is lower than the guess number
 *			      1 if num is higher than the guess number
 *               otherwise return 0
 * int guess(int num);
 */

int guess(int num) {
    // API
    return 0;
}

class Solution {
    public:
        int guessNumber(int n) {
            // O(log(N))
            int lo = 1, hi = n;
            while (lo <= hi) {
                int mid = lo + (hi - lo) / 2;
                int temp = guess(mid);
                if (temp == -1)
                    hi = mid - 1;
                else if (temp == 1)
                    lo = mid + 1;
                else
                    return mid;
            }
            return 0;
        }
};

int main(void) {
    Solution s;
}