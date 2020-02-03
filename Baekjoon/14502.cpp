#include <bits/stdc++.h>
using namespace std;
int n, m; int input[8][8];
int coronavirus[64]; int viruscnt;
int arr[3]; bool isused[64];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};
int result = 0;

void backtrack(int k) {
    if (k == 3) {
        bool visited[n][m] = {};
        for (int i = 0; i < 3; i++) {
            int idx = coronavirus[arr[i]]; visited[idx / m][idx % m] = true;
        }
        queue<pair<int, int>> Q;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                // Actually I already know where virus is... waste of time!
                if (input[i][j] == 2) {
                    Q.push({i, j}); visited[i][j] = true;
                    while (!Q.empty()) {
                        auto current = Q.front(); Q.pop();
                        for (int dir = 0; dir < 4; dir++) {
                            int X = current.first + dx[dir], Y = current.second + dy[dir];
                            if (X < 0 || Y < 0 || X >= n || Y >= m) { continue; }
                            if (input[X][Y] == 1) { visited[X][Y] = true; continue; }
                            if (!visited[X][Y] && input[X][Y] == 0) {
                                visited[X][Y] = true; Q.push({X, Y}); continue;
                            }
                            if (visited[X][Y] && input[X][Y] == 0) { continue; } 
                        }
                    }
                }    
            }
        }
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!visited[i][j] && input[i][j] == 0) { cnt++; }
            }
        }
        if (cnt > result) { result = cnt; }
        return;
    }
    for (int i = 0; i < viruscnt; i++) {
        if (k == 0 || arr[k - 1] < i) {
            arr[k] = i; isused[i] = true; backtrack(k + 1); isused[i] = false;
        }
    }
}

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> input[i][j];
            if (input[i][j] == 0) {
                coronavirus[viruscnt++] = m * i + j;
            }
        }
    }
    backtrack(0);
    cout << result;
}