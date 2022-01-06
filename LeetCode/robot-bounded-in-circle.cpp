// 1041. Robot Bounded In Circle
#include <iostream>
#include <string>
using namespace std;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

class Solution {
public:
    bool isRobotBounded(string instructions) {
        // O(N)
        int N = instructions.size();
        int dir = 0, x = 0, y = 0;
        for (int i = 0; i < N; i++) {
            char c = instructions[i];
            if (c == 'G') {
                x += dx[dir];
                y += dy[dir];
            } else if (c == 'L')
                dir = (dir + 1) % 4;
            else if (c == 'R')
                dir = (dir + 3) % 4;
        }
        if (x == 0 && y == 0)
            return true;
        if (dir != 0)
            return true;
        return false;        
    }
};

int main(void) {
    Solution s;
}