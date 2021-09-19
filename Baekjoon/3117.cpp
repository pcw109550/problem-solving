#include <bits/stdc++.h>
using namespace std;

int n, k, m;
int start[100002];
int p[100002][31];

int f(int l, int x) {
    int idx = 0;
    while (l > 0) {
        if (l & 1) 
            x = p[x][idx];
        l >>= 1;
        idx++;
    }
    return x;
}

int main(void) {
    // O(N * log(M))
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> n >> k >> m;
    for (int i = 1; i <= n; i++)
        cin >> start[i];
    for (int i = 1; i <= k; i++)
        cin >> p[i][0];
    for (int i = 1; i <= 30; i++)
        for(int j = 1; j <= k; j++)
            p[j][i] = p[p[j][i - 1]][i - 1];
    for (int i = 1; i <= n; i++)
        cout << f(m - 1, start[i]) << ' ';
}