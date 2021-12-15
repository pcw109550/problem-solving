// 529. Minesweeper
#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;
int dx[8] = {1, 1, 1, 0, 0, -1, -1, -1};
int dy[8] = {1, 0, -1, 1, -1, 1, 0, -1};

class Solution {
    int M, N;
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        // O(M * N)
        M = board.size(), N = board[0].size();
        int x = click[0], y = click[1];
        if (board[x][y] == 'M') {
            board[x][y] = 'X';
            return board;
        }
        // always board[x][y] == 'E'
        int cnt = adjcnt(board, x, y);
        if (cnt > 0) {
            board[x][y] = '0' + cnt;
            return board;
        }
        queue<pair<int, int> > Q;
        Q.push({x, y}); board[x][y] = 'B';
        while (!Q.empty()) {
            auto cur = Q.front(); Q.pop();
            for (int dir = 0; dir < 8; dir++) {
                int X = cur.first + dx[dir];
                int Y = cur.second + dy[dir];
                if (X < 0 || Y < 0 || X >= M || Y >= N)
                    continue;
                if (board[X][Y] == 'E') {
                    int cnt = adjcnt(board, X, Y);
                    if (cnt > 0)
                        board[X][Y] = '0' + cnt;
                    else {
                        board[X][Y] = 'B';
                        Q.push({X, Y});
                    }
                }
            }
        }
        return board;
    }
    
    inline int adjcnt(vector<vector<char> > &board, int x, int y) {
        // O(1)
        int cnt = 0;
        for (int dir = 0; dir < 8; dir++) {
            int X = x + dx[dir];
            int Y = y + dy[dir];
            if (X < 0 || Y < 0 || X >= M || Y >= N)
                continue;
            if (board[X][Y] == 'M')
                cnt++;
        }
        return cnt;
    }
};

int main(void) {
    Solution s;
}