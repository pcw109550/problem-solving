#include <bits/stdc++.h>
using namespace std;
#define INF 100000

int D[1001][1001];

int main(void) {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int N, M, X, a, b, c; cin >> N >> M >> X;
    fill(*D, *D + 1001 * 1001, INF);
    for (int i = 0; i < M; i++) {
        cin >> a >> b >> c;
        D[a][b] = c;
    }
    for (int i = 1; i <= N; i++) {
        D[i][i] = 0;
    }
    // Floyd-Warshall O(N ** 3)
    for (int i = 1; i <= N; i++) {
        for (int s = 1; s <= N; s++) {
            for (int t = 1; t <= N; t++) {
                if (D[s][t] > D[s][i] + D[i][t]) {
                    D[s][t] = D[s][i] + D[i][t];
                }
            }
        }
    }
    int Max = 0;
    for (int i = 1; i <= N; i++) {
        if (Max < D[i][X] + D[X][i]) {
            Max = D[i][X] + D[X][i];
        }
    }
    cout << Max;
    // TODO: Use Dijkstra for O(N ** 2)
}