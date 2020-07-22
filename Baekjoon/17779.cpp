#include<bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int N, result = 1 << 30;
    cin >> N;
    int Map[N][N];
    for (int r = 0; r < N; r++)
        for (int c = 0; c < N; c++)
            cin >> Map[r][c];
    for (int r = 0; r < N; r++) {
        for (int c = 0; c < N; c++) {
            for (int d1 = 1; d1 <= c; d1++) {
                for (int d2 = 1; d2 <= N - c - 1; d2++) {
                    if (d1 + d2 > N - r - 1)
                        continue;
                    bool fifth[N][N] = {};
                    int sum[5] = {};
                    for (int x = 0; x <= d1; x++) {
                        for (int y = 0; y <= d2; y++) {
                            fifth[r + x + y][c - x + y] = true;   
                            if (x != d1 && y != d2)
                                fifth[r + x + y + 1][c - x + y] = true;
                        }
                    }
                    for (int i = 0; i < N; i++) {
                        for (int j = 0; j < N; j++) {
                            if (fifth[i][j])
                                sum[4] += Map[i][j];
                            else {
                                if (1 <= i + 1 && i + 1 < r + 1 + d1 &&
                                    1 <= j + 1 && j + 1 <= c + 1) {
                                    sum[0] += Map[i][j];
                                } else if (1 <= i + 1 && i + 1 <= r + 1 + d2 &&
                                    c + 1 < j + 1 && j + 1 <= N) {
                                    sum[1] += Map[i][j];
                                } else if (r + 1 + d1 <= i + 1 && i + 1 <= N &&
                                    1 <= j + 1 && j + 1 < c + 1 - d1 + d2) {
                                    sum[2] += Map[i][j];
                                } else if (r + 1 + d2 < i + 1 && i + 1 <= N &&
                                    c + 1 - d1 + d2 <= j + 1 && j + 1 <= N) {
                                    sum[3] += Map[i][j];
                                }
                            }
                        }
                    }
                    int delta = *max_element(sum, sum + 5) - *min_element(sum, sum + 5);
                    result = min(result, delta);
                }
            }
        }
    }
    cout << result;
}