#include <bits/stdc++.h>
using namespace std;

#define MAX 100001

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);
    int N, K; cin >> N >> K;
    queue<pair<int, int>> Q; bool visited[MAX] = {};
    Q.push({N, 0}); visited[N] = true;
    while (!Q.empty()) {
        pair<int, int> current = Q.front(); Q.pop();
        int pos = current.first, step = current.second;
        if (pos == K) { cout << step; return 0; }
        int X = pos * 2;
        while (X != 0 && X < MAX) {
            if (!visited[X]) { Q.push({X, step}); visited[X] = true; }
            if (X == K) {cout << step; return 0; }
            X *= 2;
        }
        if (pos - 1 >= 0 && !visited[pos - 1]) {
            Q.push({pos - 1, step + 1}); visited[pos - 1] = true;
        }
        if (pos + 1 < MAX && !visited[pos + 1]) {
            Q.push({pos + 1, step + 1}); visited[pos + 1] = true;
        }
    }

}