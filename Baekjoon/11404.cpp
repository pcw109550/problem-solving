#include <bits/stdc++.h>
using namespace std;
#define INF 10000001

int D[101][101];

int main(void) {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int N, M, a, b, c; cin >> N >> M;
    fill(*D, *D + 101 * 101, INF);
    for (int i = 0; i < M; i++) {
        cin >> a >> b >> c;
        D[a][b] = min(D[a][b], c);
    }
    for (int i = 1; i <= N; i++) {
        D[i][i] = 0;
    }
    // Floyd-Warshall O(N ** 3)
    for (int i = 1; i <= N; i++) {
        for (int s = 1; s <= N; s++) {
            for (int t = 1; t <= N; t++) {
                D[s][t] = min(D[s][t], D[s][i] + D[i][t]);
            }
        }
    }
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cout << (D[i][j] == INF ? 0 : D[i][j]) << ' ';
        }
        cout << '\n';
    }
}