// 794. Valid Tic-Tac-Toe State
#include <iostream>
#include <vector>
#include <string>

class Solution {
    public:
        bool validTicTacToe(std::vector<std::string>& board) {
            // O(1)
            int numO = 0, numX = 0;
            for (int i = 0; i < 3; i++)
                for (int j = 0; j < 3; j++) {
                    if (board[i][j] == 'X')
                        numX++;
                    else if (board[i][j] == 'O')
                        numO++;
                }
            if (numX != numO + 1 && numX != numO)
                return false;
            int numBingoX = 0, numBingoO = 0;
            for (int i = 0; i < 3; i++)
                if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
                    if (board[0][i] == 'X')
                        numBingoX++;
                    else if (board[0][i] == 'O')
                        numBingoO++;
                }
            for (int i = 0; i < 3; i++)
                if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
                    if (board[i][0] == 'X')
                        numBingoX++;
                    else if (board[i][0] == 'O')
                        numBingoO++;
                }
            if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
                if (board[0][0] == 'X')
                    numBingoX++;
                else if (board[0][0] == 'O')
                    numBingoO++;
            }
            if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
                if (board[0][2] == 'X')
                    numBingoX++;
                else if (board[0][2] == 'O')
                    numBingoO++;
            }
            if (numBingoX > 0 && numBingoO > 0)
                return false;
            if (numBingoX == 1 && numX == numO)
                return false;
            if (numBingoO == 1 && numX == numO + 1)
                return false;
            return true;
        }
};

int main(void) {
    Solution s;
}