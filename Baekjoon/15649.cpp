#include <bits/stdc++.h>
using namespace std;
int n, m;
bool isused[8]; int arr[8];

void backtrack(int k) {
    if (k == m) { for (int i = 0; i < m; i++) { cout << arr[i] << " "; } cout << "\n"; return; }
    for (int i = 0; i < n; i++) {
        if (!isused[i]) { isused[i] = true; arr[k] = i + 1; backtrack(k + 1); isused[i] = false; }
    }
}

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);
    int N, M; cin >> N >> M; n = N; m = M;
    backtrack(0);
}