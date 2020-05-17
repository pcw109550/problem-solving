#include <bits/stdc++.h>
using namespace std;
#define INF 1e7

int main(void) {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int N, M, a, b, weight; cin >> N >> M;
    int D[N + 1][N + 1] = {}, path[N + 1][N + 1] = {};
    fill(*D, *D + (N + 1) * (N + 1), INF);
    for (int i = 0; i < M; i++) {
        cin >> a >> b >> weight;
        D[a][b] = D[b][a] = weight;
        path[a][b] = b;
        path[b][a] = a;
    }
    for (int i = 1; i <= N; i++) {
        D[i][i] = 0;
    }
    // FloydWarshall O(N ** 3)
    for (int i = 1; i <= N; i++) {
        for (int s = 1; s <= N; s++) {
            for (int t = 1; t <= N; t++) {
                if (D[s][t] > D[s][i] + D[i][t]) {
                    D[s][t] = D[s][i] + D[i][t];
                    path[s][t] = path[s][i];
                }
            }
        }
    }
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (i == j) { cout << "- "; }
            else        { cout << path[i][j] << ' '; }
        }
        cout << '\n';
    }
}