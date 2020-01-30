#include <bits/stdc++.h>
using namespace std;
int m, n;
int data[8], arr[8]; bool visited[8];

void backtrack(int k) {
    if (k == m) { for (int i = 0; i < m; i++) { cout << data[arr[i]] << " "; } cout << '\n'; }
    int prev = -1;
    for (int i = 0; i < n; i++) {
        if (!visited[i] && prev != data[i]) {
            prev = data[i];
            arr[k] = i; visited[i] = true; backtrack(k + 1); visited[i] = false;
        }
    }
}

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);
    int N, M, temp; cin >> N >> M; n = N; m = M;
    list<int> input;
    for (int i = 0; i < N; i++) { cin >> temp; input.push_front(temp); }
    input.sort(); auto it = input.begin(); temp = 0;
    while (it != input.end()) {data[temp++] = *it++; }
    backtrack(0);
}