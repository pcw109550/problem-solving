#include <bits/stdc++.h>
using namespace std;

int n, m, p[200002][21];

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
    // O(N * log(N) + M * log(N))
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> n;
    int a, b;
    for(int i = 1; i <= n; i++)
        cin >> p[i][0];
    for(int i = 1; i < 20; i++)
        for(int j = 1; j <= n; j++)
            p[j][i] = p[p[j][i - 1]][i - 1];
    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        cout << f(a, b) << '\n';
    }
}