#include <bits/stdc++.h>
using namespace std;
#define INF 10000001

int D[101][101];
int E[101][101];

int main(void) {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int N, M, a, b, c; cin >> N >> M;
    fill(*D, *D + 101 * 101, INF);
    for (int i = 0; i < M; i++) {
        cin >> a >> b >> c;
        D[a][b] = min(D[a][b], c);
        if (D[a][b] == c) {
            E[a][b] = b;
        }
    }
    for (int i = 1; i <= N; i++) {
        D[i][i] = 0;
    }
    // Floyd-Warshall O(N ** 3) with path finding
    for (int i = 1; i <= N; i++) {
        for (int s = 1; s <= N; s++) {
            for (int t = 1; t <= N; t++) {
                if (D[s][t] > D[s][i] + D[i][t]) {
                    // bypass s == i or s == t
                    D[s][t] = D[s][i] + D[i][t];
                    E[s][t] = E[s][i];
                }
            }
        }
    }
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cout << (D[i][j] == INF ? 0 : D[i][j]) << ' ';
        }
        cout << '\n';
    }
    for (int s = 1; s <= N; s++) {
        for (int t = 1; t <= N; t++) {
            if (D[s][t] == INF || s == t) {
                cout << 0 << '\n';
                continue;
            }
            vector<int> path;
            int cur = s;
            while (cur != t) {
                path.push_back(cur);
                cur = E[cur][t];
            }
            path.push_back(t);
            cout << path.size() << ' ';
            for (auto it = path.begin(); it != path.end(); it++) {
                cout << *it << ' ';
            }
            cout << '\n';
        }
    }
}