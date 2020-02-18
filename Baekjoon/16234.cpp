#include <bits/stdc++.h>
using namespace std;
int N, L, R; int input[50][50];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

inline bool openborder(int a, int b) {
    int diff = abs(a - b);
    return L <= diff and diff <= R;
}

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> L >> R;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> input[i][j];
        }
    }

    bool changed; int result = 0; queue<pair<int, int>> Q; 
    do {
        changed = false; bool visited[N][N] = {};
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (!visited[i][j]) {
                    visited[i][j] = true; list<pair<int, int>> T;
                    Q.push({i, j}); T.push_back({i, j}); int cnt = 1, sum = input[i][j];
                    while (!Q.empty()) {
                        auto current = Q.front(); Q.pop();
                        for (int dir = 0; dir < 4; dir++) {
                            int X = current.first + dx[dir], Y = current.second + dy[dir];
                            if (X < 0 || Y < 0 || X >= N || Y >= N) { continue; }
                            if (!visited[X][Y] && openborder(input[current.first][current.second], input[X][Y])) {
                                visited[X][Y] = true; Q.push({X, Y}); T.push_back({X, Y}); cnt++;
                                sum += input[X][Y]; continue;
                            }
                        }
                    }
                    if (cnt != 1) { changed = true; } else { continue; }
                    for (auto it = T.begin(); it != T.end(); it++) {
                        input[(*it).first][(*it).second] = sum / cnt;
                    }
                }
            }
        }
        if (changed) { result++; }
    } while (changed);
    cout << result;
}