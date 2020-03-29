#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int N, T, x, y; cin >> N >> T;
    vector<bool> Map(N * N, false);
    for (int i = 0; i < T; i++) {
        cin >> x >> y; x--; y--;
        Map[x + N * y] = Map[y + N * x] = true;
    } // Use Adjacency list for less memory use
    pair<bool, int> visited[N]; queue<int> Q;
    visited[0] = {true, 0}; Q.push(0); int result = 0;
    while (!Q.empty()) {
        int current = Q.front(); Q.pop();
        for (int i = 0; i < N; i++) {
            if(!visited[i].first && Map[i + current * N]) {
                visited[i] = {true, visited[current].second + 1};
                if (visited[current].second + 1 <= 2) {
                    result++; Q.push(i);
                }
            }
        }
    }
    cout << result;
}