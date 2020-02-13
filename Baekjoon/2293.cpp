#include <bits/stdc++.h>
using namespace std;
int coin[100];
int d1[10001], d2[10001];

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, k; cin >> n >> k;
    for (int i = 0; i < n; i++) { cin >> coin[i]; }
    for (int i = 0; i <= k; i += coin[0]) { d1[i] = 1; }
    for (int i = 1; i < n; i++) {
        memset((void *)d2, 0, sizeof(int) * (k + 1));
        for (int j = 0; j <= k; j++) {
            d2[j] = d1[j];
            if (j >= coin[i]) { d2[j] += d2[j - coin[i]]; }
        }
        for (int j = 0; j <= k; j++) {
            d1[j] = d2[j];
        }
    }
    cout << d1[k];
}