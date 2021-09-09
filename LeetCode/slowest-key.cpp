// 1629. Slowest Key
#include <iostream>
#include <vector>
#include <string>
#include <climits>
using namespace std;

class Solution {
public:
    char slowestKey(vector<int>& releaseTimes, string keysPressed) {
        // O(N)
        char result = '\0';
        int N = releaseTimes.size();
        int dur = INT_MIN;
        for (int i = 0; i < N; i++) {
            int cur_dur = releaseTimes[i] - (i >= 1 ? releaseTimes[i - 1] : 0);
            if (dur < cur_dur) {
                dur = cur_dur;
                result = keysPressed[i];
            } else if (dur == cur_dur && result < keysPressed[i])
                result = keysPressed[i];
        }
        return result;
    }
};

int main(void) {
    Solution s;
}