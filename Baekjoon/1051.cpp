#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    char c;
    int M, N; cin >> M >> N;
    vector<vector<int> > D(M, vector<int>(N));
    for (int i = 0; i < M; i++)
        for (int j = 0; j < N; j++) {
            cin >> c;
            D[i][j] = c - '0';
        }
    int s = min(M, N);
    int result = 0;
    for (int l = 1; l <= s; l++) {
        for (int i = 0; i <= M - l; i++) {
            for (int j = 0; j <= N - l; j++) {
                if (D[i][j] == D[i][j + l - 1] && D[i][j] == D[i + l - 1][j])
                    if (D[i][j] == D[i + l - 1][j + l - 1]) {
                        result = max(result, l * l);
                    }
                }
            }
        }
    cout << result;
}