// 2139. Minimum Moves to Reach Target Score
#include <iostream>
using namespace std;

class Solution {
public:
    int minMoves(int target, int maxDoubles) {
        // O(log(N))
        int result = 0;
        int cur = target;
        while (cur > 1) {
            if (cur % 2 == 1 || maxDoubles == 0) {
                cur -= 1;
                result += 1;
            } else if (maxDoubles > 0) {
                cur /= 2;
                result += 1;
                maxDoubles -= 1;
            }
            if (maxDoubles == 0 && cur > 1) {
                result += cur - 1;
                break;
            }
        }
        return result;
    }
};

int main(void) {
    Solution s;
}
