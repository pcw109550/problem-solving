#include <bits/stdc++.h>
using namespace std;
#define MAX 1 << 30

int main(void) {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    // O(N)
    int N, result = MAX; cin >> N;
    int R[N], G[N], B[N];
    for (int i = 0; i < N; i++) 
        cin >> R[i] >> G[i] >> B[i];
    for (int c = 0; c < 3; c++) {
        int cand = MAX;
        int D[3][1000] = {};
        D[0][0] = R[0]; D[1][0] = G[0]; D[2][0] = B[0];
        for (int i = 0; i < 3; i++)
            if (i != c)
                D[i][0] = MAX;
        for (int i = 1; i < N; i++) {
            D[0][i] = min(D[1][i - 1], D[2][i - 1]) + R[i];
            D[1][i] = min(D[0][i - 1], D[2][i - 1]) + G[i];
            D[2][i] = min(D[0][i - 1], D[1][i - 1]) + B[i];
        }
        for (int i = 0; i < 3; i++)
            if (i != c)
                cand = min(cand, D[i][N - 1]);
        result = min(result, cand);
    }
    cout << result;
}