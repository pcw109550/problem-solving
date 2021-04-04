#include <bits/stdc++.h>
using namespace std;
#define RING 1000000003

int main(void) {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int N, K; cin >> N >> K;
    if (N / 2 < K) {
        cout << 0;
        return 0;
    }
    vector<vector<int> > D(N - K + 1, vector<int>(N - K + 1, 0));
    for (int i = 1; i <= N - K; i++) {
        D[i][0] = D[i][i] = 1;
        for (int j = 1; j < i; j++)
            D[i][j] = (D[i - 1][j] + D[i - 1][j - 1]) % RING;
    }
    int result = (D[N - K - 1][K - 1] + D[N - K][K]) % RING;
    cout << result;
}