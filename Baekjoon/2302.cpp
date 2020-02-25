#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);
    int N, M, temp, Max = 0, start = 1, idx = 0; cin >> N >> M; int len[40] = {}; 
    for (int i = 0; i < M; i++) {
        cin >> temp; len[idx++] = temp - start; start = temp + 1;
        Max = max(Max, len[idx - 1]);
    } len[idx++] = N + 1 - start; Max = max(Max, len[idx - 1]);
    int D[Max + 1] = {}; D[0] = D[1] = 1;
    for (int i = 2; i <= Max; i++) {
        D[i] = D[i - 1] + D[i - 2];
    }
    int result = 1;
    for (int i = 0; i < idx; i++) {
        result *= D[len[i]];
    }
    cout << result;
}