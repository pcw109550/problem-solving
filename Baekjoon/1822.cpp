#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);
    int N, M; cin >> N >> M; int A[N], B[M];
    for (int i = 0; i < N; i++) { cin >> A[i]; } sort(A, A + N);
    for (int i = 0; i < M; i++) { cin >> B[i]; } sort(B, B + M);
    int cnt = 0; int output[N] = {};
    for (int i = 0; i < N; i++) {
        if (!binary_search(B, B + M, A[i])) { output[cnt++] = A[i]; }
    }
    cout << cnt << '\n';
    if (cnt != 0) {
        for (int i = 0; i < cnt; i++) { cout << output[i] << " "; }
    }
}