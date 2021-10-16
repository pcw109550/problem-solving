// 79. Word Search
#include <iostream>
#include <vector>
#include <string>
using namespace std;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

class Solution {
    bool result;
    int M, N;
public:
    bool exist(vector<vector<char>>& board, string word) {
        // O(M * N * 3 ** L)
        M = board.size(), N = board[0].size();
        vector<vector<bool> > visited (M, vector<bool>(N, false));
        for (int i = 0; i < M; i++)
            for (int j = 0; j < N; j++) {
                backtrack(board, visited, word, 0, i, j);
                if (result)
                    return true;
            }    
        return false;
    }
    
    void backtrack(vector<vector<char> > &board, vector<vector<bool> > &visited, string &word, int idx, int i, int j) {
        if (result == true || idx == word.size()) {
            result = true;
            return;
        }
        if (i < 0 || j < 0 || i >= M || j >= N)
            return;
        if (board[i][j] != word[idx])
            return;
        if (visited[i][j])
            return;
        visited[i][j] = true;
        for (int dir = 0; dir < 4; dir++) {
            int x = i + dx[dir];
            int y = j + dy[dir];
            backtrack(board, visited, word, idx + 1, x, y);
        }
        visited[i][j] = false;
    }
};

int main(void) {
    Solution s;
}