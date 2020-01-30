#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);
    int F, S, G, U, D; cin >> F >> S >> G >> U >> D;
    bool visited[F + 1] = {};
    queue<pair<int, int>> Q;
    Q.push({S, 0}); visited[S] = true;
    while (!Q.empty()) {
        pair<int, int> current = Q.front(); Q.pop();
        int idx = current.first; int step = current.second;
        if (idx == G) { cout << step; return 0; }
        if (idx + U <= F && !visited[idx + U]) {
            visited[idx + U] = true; Q.push({idx + U, step + 1});
        }
        if (idx - D >= 1 && !visited[idx - D]) {
            visited[idx - D] = true; Q.push({idx - D, step + 1});
        }
    }
    cout << "use the stairs";
}