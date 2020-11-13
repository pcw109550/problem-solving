// 36. Valid Sudoku
#include <iostream>
#include <vector>

class Solution {
    public:
        bool isValidSudoku(std::vector<std::vector<char> >& board) {
            // O(N)
            std::vector<bool> check(9, false);
            for (int i = 0; i < 9; i++) {
                for (int j = 0; j < 9; j++) {
                    int current = translate(board[i][j]);
                    if (current == -1)
                        continue;
                    if (check[current])
                        return false;
                    check[current] = true;
                }
                std::fill(check.begin(), check.end(), false);
            }
            for (int i = 0; i < 9; i++) {
                for (int j = 0; j < 9; j++) {
                    int current = translate(board[j][i]);
                    if (current == -1)
                        continue;
                    if (check[current])
                        return false;
                    check[current] = true;
                }
                std::fill(check.begin(), check.end(), false);
            }
            for (int i = 1; i < 9; i += 3)
                for (int j = 1; j < 9; j += 3) {
                    for (int x = -1; x <= 1; x++)
                        for (int y = -1; y <= 1; y++) {
                            int current = translate(board[i + x][j + y]);
                            if (current == -1)
                                continue;
                            if (check[current])
                                return false;
                            check[current] = true;
                        }
                    std::fill(check.begin(), check.end(), false);
                }
            return true;
        }
    
        inline int translate(char c) {
            return c == '.' ? -1 : c - '1';
        }
};

int main(void) {
    Solution s;
}