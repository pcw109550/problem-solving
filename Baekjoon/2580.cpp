#include <bits/stdc++.h>
using namespace std;

bool is_valid(std::vector<std::vector<int> >& board, int row, int col, int c) {
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

bool backtrack(std::vector<std::vector<int> >& board) {
    for (int i = 0; i < 9; i++)
        for (int j = 0; j < 9; j++)
            if (board[i][j] == 0) {
                for (int c = 1; c <= 9; c++) {
                    if (is_valid(board, i, j, c)) {
                        board[i][j] = c;
                        if (backtrack(board))
                            return true;
                        board[i][j] = 0;
                    }  
                }
                return false;
            }
    return true;
}

int main(void) {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    vector<vector<int> > board (9, vector<int> (9));
    for (int i = 0; i < 9; i++)
        for (int j = 0; j < 9; j++)
            cin >> board[i][j];
    backtrack(board);
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) 
            cout << board[i][j] << ' ';
        cout << '\n';
    }
}
