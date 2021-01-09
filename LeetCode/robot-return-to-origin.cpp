// 657. Robot Return to Origin
#include <iostream>
#include <string>

class Solution {
    public:
        bool judgeCircle(std::string moves) {
            // O(N)
            int x = 0, y = 0;
            for (auto it : moves) {
                switch(it) {
                    case 'R':
                        x++;
                        break;
                    case 'L':
                        x--;
                        break;
                    case 'U':
                        y++;
                        break;
                    case 'D':
                        y--;
                        break;
                    default:
                        break;
                }
            }
            return x == 0 && y == 0;
        }
};

int main(void) {
    Solution s;
}