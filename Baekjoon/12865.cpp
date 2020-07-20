#include<bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    // 01 Knapsack
    int N, K;
    cin >> N >> K;
    int W[N + 1], V[N + 1];
    for (int i = 1; i <= N; i++)
        cin >> W[i] >> V[i];
    int D[K + 1][N + 1] = {};
    for (int i = 1; i <= K; i++) {
        for (int j = 1; j <= N; j++) {
            if (i >= W[j])
                D[i][j] = max(D[i][j - 1], D[i - W[j]][j - 1] + V[j]);
            else
                D[i][j] = D[i][j - 1];
        }
    }
    cout << D[K][N];
}   