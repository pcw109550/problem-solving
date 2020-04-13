#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int N, M, x1, y1, x2, y2, temp; cin >> N >> M; int D[N + 1][N + 1] = {};
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> temp;
            D[i + 1][j + 1] = D[i][j + 1] + D[i + 1][j] - D[i][j] + temp;
        }
    }
    for (int t = 0; t < M; t++) {
        cin >> x1 >> y1 >> x2 >> y2;
        cout << D[x2][y2] - D[x1 - 1][y2] - D[x2][y1 - 1] + D[x1 - 1][y1 - 1] << '\n';
    }
}