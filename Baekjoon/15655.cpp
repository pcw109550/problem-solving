#include <bits/stdc++.h>
using namespace std;
int m, n;
int data[8], arr[8]; bool visited[8];

void backtrack(int k) {
    if (m == k) { for (int i = 0; i < m; i++) { cout << data[arr[i]] << " ";} cout << '\n'; return; }
    for (int i = 0; i < n; i++) {
        if ( k == 0 || !visited[i] && arr[k - 1] < i) { arr[k] = i; visited[i] = true; backtrack(k + 1); visited[i] = false; }
    }
}

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);
    int N, M, temp; cin >> N >> M; list<int> input; m = M; n = N;
    for (int i = 0; i < N; i++) { cin >> temp; input.push_front(temp); }
    input.sort(); auto it = input.begin(); temp = 0;
    while (it != input.end()) {
        data[temp++] = *it++;
    }
    backtrack(0);
}