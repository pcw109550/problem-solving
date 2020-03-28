#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);
    int N, M, x, y; cin >> N >> M; bool Map[N][N] = {};
    for (int i = 0; i < M; i++) {
        cin >> x >> y; x--; y--; Map[x][y] = Map[y][x] = 1;
    }
    bool visited[N] = {}; int result = 0;
    for (int i = 0; i < N; i++) { // O(N ** 2)
        if (!visited[i]) {
            queue<int> Q; Q.push(i); visited[i] = true;
            while (!Q.empty()) {
                int current = Q.front(); Q.pop();
                for (int j = 0; j < N; j++) {
                    if (Map[current][j] && !visited[j]) {
                        visited[j] = true; Q.push(j); 
                    }
                }
            }
            result++;
        }
    }
    cout << result;
}