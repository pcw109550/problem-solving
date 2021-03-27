// 37. Sudoku Solver
#include <iostream>
#include <vector>
#include <unordered_set>
#include <string>

class Solution {
    public:
        void solveSudoku(std::vector<std::vector<char> >& board) {
            backtrack(board);
        }
    
        bool backtrack(std::vector<std::vector<char> >& board) {
            // O(N!)
            for (int i = 0; i < 9; i++)
                for (int j = 0; j < 9; j++)
                    if (board[i][j] == '.') {
                        for (char c = '1'; c <= '9'; c++) {
                            if (is_valid(board, i, j, c)) {
                                board[i][j] = c;
                                if (backtrack(board))
                                    return true;
                                board[i][j] = '.';
                            }  
                        }
                        return false;
                    }
            return true;
        }
    
        bool is_valid(std::vector<std::vector<char> >& board, int row, int col, char c) {
            int regionRow = 3 * (row / 3);
            int regionCol = 3 * (col / 3);
            for (int i = 0; i < 9; i++) {
                if (board[i][col] == c)
                    return false;
                if (board[row][i] == c)
                    return false;
                if (board[regionRow + i / 3][regionCol + i % 3] == c)
                    return false;
            }
            return true;
        }
};

int main(void) {
    Solution s;
}