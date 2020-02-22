#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);
    int N; cin >> N; int T[N + 1] = {}, P[N + 1] = {};
    for (int i = 1; i <= N; i++) { cin >> T[i] >> P[i]; }
    int D[N + 2] = {}, Max = 0;
    for (int i = 1; i <= N + 1; i++) {
        Max = 0;
        for (int j = 1; j < i; j++) {
            if (T[i - j] <= j) { Max = max(Max, D[i - j] + P[i - j]); }
        }
        D[i] = max(D[i], Max);
    }
    cout << D[N + 1];
}