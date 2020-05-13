#include <bits/stdc++.h>
using namespace std;
#define INF 512

int main(void) {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int N, x1, x2; cin >> N; int D[N + 1][N + 1];
    fill(*D, *D + (N + 1) * (N + 1), INF);
    pair<int, int> line[N + 1] = {};
    for (int i = 1; i <= N; i++) {
        cin >> x1 >> x2; line[i] = {x1, x2};
    }
    for (int i = 1; i <= N; i++) {
        for (int j = i; j <= N; j++) {
            if (i == j) { D[i][j] = 0; }
            else {
                int x1, x2, y1, y2;
                tie(x1, x2) = line[i];
                tie(y1, y2) = line[j];
                if (x2 - x1 + y2 - y1 >= max(abs(x1 - y2), abs(x2 - y1))) {
                    D[i][j] = D[j][i] = 1;
                }
            }
        }
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
    int Q, x, y; cin >> Q;
    while (Q--) {
        cin >> x >> y;
        cout << (D[x][y] == INF ? -1 : D[x][y]) << '\n';
    }
}