#include <bits/stdc++.h>
using namespace std;
int n, m;
int arr[8];

void backtrack(int k) {
    if (k == m) { for (int i = 0; i < m; i++) { cout << arr[i] << " "; } cout << '\n'; return; }
    for (int i = (0 < k ? arr[k - 1] - 1: 0); i < n; i++) {
        arr[k] = i + 1; backtrack(k + 1); 
    }
}

int main(void) {
    int N, M; cin >> N >> M; n = N; m = M;
    backtrack(0);
}