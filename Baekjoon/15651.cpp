#include <bits/stdc++.h>
using namespace std;
int m, n;
int arr[8];

void backtrack(int k) {
    if (m == k) { for(int i = 0; i < m; i++) { cout << arr[i] << " "; } cout << "\n"; return; }
    for (int i = 0; i < n; i++) {
        arr[k] = i + 1; backtrack(k + 1);
    }
}

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);
    int N, M; cin >> N >> M; n = N; m = M;
    backtrack(0);
}