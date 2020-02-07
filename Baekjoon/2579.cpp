#define PLAN 1
#include <bits/stdc++.h>
using namespace std;
int S[301];

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);
    int N, sum = 0; cin >> N; for (int i = 1; i <= N; i++) { cin >> S[i]; sum += S[i]; }
#if PLAN == 0
    int D[301][3];
    D[1][1] = S[1]; D[1][2] = 0;
    for (int k = 2; k <= N; k++) {
        D[k][1] = max(D[k - 2][1], D[k - 2][2]) + S[k];
        D[k][2] = D[k - 1][1] + S[k];
    }
    cout << max(D[N][1], D[N][2]);
#endif
#if PLAN == 1
    int D[301];
    D[1] = S[1]; D[2] = S[2]; D[3] = S[3];
    for (int k = 4; k <= N; k++) {
        D[k] = min(D[k - 2], D[k - 3]) + S[k];
    }
    cout << sum - min(D[N - 1], D[N - 2]);
#endif
}