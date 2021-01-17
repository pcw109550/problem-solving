// 130. Surrounded Regions
#include <iostream>
#include <vector>
#include <queue>
#include <utility>
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

class Solution {
    public:
        void solve(std::vector<std::vector<char> >& board) {
            // O(M * N)
            int M = board.size();
            if (M == 0)
                return;
            int N = board[0].size();
            std::vector<std::vector<bool> > visited(M, std::vector<bool> (N, false));
            for (int i = 0; i < M; i++) {
                for (int j = 0; j < N; j++) {
                    if (board[i][j] == 'X' || visited[i][j])
                        continue;
                    std::queue<std::pair<int, int> > Q;
                    std::vector<std::pair<int, int> > cand;
                    Q.push({i, j}); visited[i][j] = true;
                    cand.push_back({i, j});
                    bool reached_border = false;
                    while (!Q.empty()) {
                        auto current = Q.front(); Q.pop();
                        for (int dir = 0; dir < 4; dir++) {
                            int X = current.first + dx[dir];
                            int Y = current.second + dy[dir];
                            if (X < 0 || Y < 0 || X >= M || Y >= N) {
                                reached_border = true;
                                continue;
                            }
                            if (!visited[X][Y] && board[X][Y] == 'O') {
                                visited[X][Y] = true;
                                Q.push({X, Y}); cand.push_back({X, Y});
                            }
                        }
                    }
                    if (!reached_border)
                        for (auto current : cand)
                            board[current.first][current.second] = 'X';
                }
            }
        }
};

int main(void) {
    Solution s;
}