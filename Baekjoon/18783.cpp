#include <bits/stdc++.h>
using namespace std;

int n, m, k;
int p[200002][31];

int f(int k, int x) {
    int idx = 0;
    while (k > 0) {
        if (k & 1)
            x = p[x][idx]; 
        k >>= 1;
        idx++;
    }
    return x;
}

int main(void) {
    // O(M * N + N * log(K))
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> n >> m >> k;
    vector<int> D(n + 1);
    for (int i = 1; i <= n; i++)
        D[i] = i;
    int l, r;
    for (int i = 0; i < m; i++) {
        cin >> l >> r;
        reverse(D.begin() + l, D.begin() + r + 1);
    }
    for (int i = 1; i <= n; i++)
        p[i][0] = D[i];
    for (int i = 1; i <= 30; i++)
        for (int j = 1; j <= n; j++)
            p[j][i] = p[p[j][i - 1]][i - 1];
    for (int i = 1; i <= n; i++)
        cout << f(k, i) << '\n';
}