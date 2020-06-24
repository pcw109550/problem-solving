#include <bits/stdc++.h>
using namespace std;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main(void) {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int N, M, temp, numWall = 0; cin >> N >> M;
    int Map[N][N] = {};
    vector<pair<int, int> > cands;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> temp;
            if (temp == 2) {
                cands.push_back(make_pair(i, j));
            } else {
                if (temp == 1) { numWall++; }
                Map[i][j] = temp;
            }
        }
    }
    vector<int> idx;
    vector<bool> ind;
    int Min = 1 << 30;
    for (int i = 0; i < cands.size(); i++) { idx.push_back(i); }
    for (int i = 0; i < cands.size() - M; i++) { ind.push_back(false); }
    for (int i = 0; i < M; i++) { ind.push_back(true); }
    do {
        int updated[N][N] = {}; bool visited[N][N] = {};
        int numSpreaded, totalSpreaded = 0, result = 0;
        copy(&Map[0][0], &Map[0][0] + N * N, &updated[0][0]);
        for (int i = 0; i < cands.size(); i++) {
            if (ind[i]) { 
                auto cand = cands[idx[i]];
                updated[cand.first][cand.second] = 2;
            } 
        }
        do {
            numSpreaded = 0;
            // Slow. Use BFS
            vector<pair<int, int> > virusPos;
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                    if (!visited[i][j] && updated[i][j] == 2) {
                        visited[i][j] = true;
                        for (int dir = 0; dir < 4; dir++) {
                            int X = i + dx[dir];
                            int Y = j + dy[dir];
                            if (X < 0 || Y < 0 || X >= N || Y >= N) {
                                continue;
                            }
                            if (!updated[X][Y]) {
                                virusPos.push_back(make_pair(X, Y));
                            }
                        }
                    }
                }
            }
            for (auto pos : virusPos) {
                if (!updated[pos.first][pos.second]) {
                    updated[pos.first][pos.second] = 2;
                    numSpreaded++;
                }
            }
            if (numSpreaded) { result++; }
            totalSpreaded += numSpreaded;
        } while (numSpreaded);
        if (totalSpreaded == N * N - numWall - M) {
            Min = min(result, Min);
        }
    } while (next_permutation(ind.begin(), ind.end()));
    cout << (Min == 1 << 30 ? -1 : Min);
}