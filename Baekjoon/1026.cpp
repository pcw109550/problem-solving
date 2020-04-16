#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int N, sum = 0; cin >> N; int A[N] = {}, B[N] = {};
    for (int i = 0; i < N; i++) { cin >> A[i]; }
    for (int i = 0; i < N; i++) { cin >> B[i]; }
    sort(A, A + N);
    sort(B, B + N, greater<int>());
    for (int i = 0; i < N; i++) { sum += A[i] * B[i]; }
    cout << sum;
}