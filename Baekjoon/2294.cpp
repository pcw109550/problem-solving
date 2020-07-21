#include <bits/stdc++.h>
using namespace std;
#define INF 1 << 30

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);
    int N, K; cin >> N >> K; int A[N] = {};
    for (int i = 0; i < N; i++) { cin >> A[i]; }
    int D[K + 1] = {};
    fill(D, D + K + 1, INF);
    D[0] = 0;
    for (int i = 0; i < N; i++)
        for (int j = A[i]; j <= K; j++)
            D[j] = min(D[j], D[j - A[i]] + 1);
    cout << (D[K] == INF ? -1 : D[K]);
}