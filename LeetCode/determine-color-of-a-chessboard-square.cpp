// 1812. Determine Color of a Chessboard Square
#include <iostream>
#include <string>

class Solution {
    public:
        bool squareIsWhite(std::string coordinates) {
            // O(1)
            int a = coordinates[0] - 'a';
            int b = coordinates[1] - '1';
            return (a + b) % 2;
        }
};

int main(void) {
    Solution s;
}