#include <bits/stdc++.h>
using namespace std;

inline void failure(vector<int> &S) {
    int N = S.size(), j = 0;
    int occ = 0, Max = 0;
    vector<int> f(N, 0);
    for (int i = 1; i < N; i++) {
        while (j > 0 && S[i] != S[j])
            j = f[j - 1];
        if (S[i] == S[j])
            f[i] = ++j;
        if (Max == f[i] && Max != 0)
            occ++;
        else if (Max < f[i]) {
            Max = f[i];
            occ = 1;
        }
    }
    if (Max)
        cout << Max << ' ' << occ;
    else
        cout << -1;
}

int main(void) {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int N; cin >> N;
    vector<int> P(N, 0);
    for (int i = N - 1; i >= 0; i--)
        cin >> P[i];
    int j = 0;
    failure(P);
}