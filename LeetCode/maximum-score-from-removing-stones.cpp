// 1753. Maximum Score From Removing Stones
#include <iostream>
#include <queue>
using namespace std;

class Solution {
public:
    int maximumScore(int a, int b, int c) {
        // O(N)
        int result = 0;
        priority_queue<int> PQ;
        PQ.push(a); PQ.push(b); PQ.push(c);
        while (PQ.size() >= 2) {
            int x = PQ.top(); PQ.pop();
            int y = PQ.top(); PQ.pop();
            result++;
            if (x - 1 > 0)
                PQ.push(x - 1);
            if (y - 1 > 0)
                PQ.push(y - 1);
        }
        return result;
    }
};

int main(void) {
    Solution s;
}
