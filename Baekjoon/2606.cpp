#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);
    int N, T, x, y; cin >> N >> T; bool info[N][N] = {};
    for (int t = 0; t < T; t++) {
        cin >> x >> y; x--; y--; info[x][y] = info[y][x] = true;
    }
    bool visited[N] = {}; queue<int> Q;
    Q.push({0}); visited[0] = true;
    while (!Q.empty()) {
        int current = Q.front(); Q.pop();
        for (int i = 0; i < N; i++) {
            if (!visited[i] && info[current][i]) {
                visited[i] = true; Q.push({i});
            }
        }
    }
    int result = -1;
    for (int i = 0; i < N; i++) {
        if (visited[i]) { result++; }
    }
    cout << result;
}