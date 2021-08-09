// 1284. Minimum Number of Flips to Convert Binary Matrix to Zero Matrix
#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

class Solution {
    int M, N;
public:
    int minFlips(vector<vector<int>>& mat) {
        // O(M * N * 2 ** (M * N))
        M = mat.size();
        N = mat[0].size();
        int start = encode(mat);
        vector<bool> visited (1 << (M * N), false);
        queue<pair<int, int> > Q;
        Q.push({start, 0});
        visited[start] = true;
        while (!Q.empty()) {
            auto cur = Q.front(); Q.pop();
            int s = cur.first;
            int l = cur.second;
            if (s == 0)
                return l;
            auto cur_mat = decode(s);
            for (int i = 0; i < M; i++)
                for (int j = 0; j < N; j++) {
                    cur_mat[i][j] = 1 - cur_mat[i][j];
                    for (int dir = 0; dir < 4; dir++) {
                        int X = i + dx[dir];
                        int Y = j + dy[dir];
                        if (X < 0 || Y < 0 || X >= M || Y >= N)
                            continue;
                        cur_mat[X][Y] = 1 - cur_mat[X][Y];
                    }
                    int next_s = encode(cur_mat);
                    cur_mat[i][j] = 1 - cur_mat[i][j];
                    for (int dir = 0; dir < 4; dir++) {
                        int X = i + dx[dir];
                        int Y = j + dy[dir];
                        if (X < 0 || Y < 0 || X >= M || Y >= N)
                            continue;
                        cur_mat[X][Y] = 1 - cur_mat[X][Y];
                    }
                    if (!visited[next_s]) {
                        visited[next_s] = true;
                        Q.push({next_s, l + 1});
                    }
                }
        }
        return -1;
    }
    
    inline int encode(vector<vector<int>> &mat) {
        int elem = 0;
        for (int i = 0; i < M; i++)
            for (int j = 0; j < N; j++) {
                elem <<= 1;
                elem |= mat[i][j];
            }
        return elem;
    }
    
    vector<vector<int>> decode(int elem) {
        vector<vector<int>> mat (M, vector<int>(N, 0));
        for (int i = M - 1; i >= 0; i--)
            for (int j = N - 1; j >= 0; j--) {
                mat[i][j] = elem & 1;
                elem >>= 1;
            }
        return mat;
    }
};

int main(void) {
    Solution s;
}