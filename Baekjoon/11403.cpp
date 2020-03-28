#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);
    int N; cin >> N; int Map[N][N] = {};
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> Map[i][j];
        }
    }
    for (int i = 0; i < N; i++) { // O(n ** 3)
        queue<int> Q; bool visited[N] = {};
        visited[i] = true; Q.push(i);
        while (!Q.empty()) {
            int current = Q.front(); Q.pop();
            for (int j = 0; j < N; j++) {
                if (!visited[j] && Map[current][j]) {
                    visited[j] = true; Q.push(j); Map[i][j] = true;
                } else if (Map[current][j] && j == i) {
                    Map[i][i] = true;
                }
            }
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << Map[i][j] << (j == N - 1 ? '\n' : ' ') ;
        }
    }
}