#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);
    int N; cin >> N; int A[N], B[N], C[N], D[N];
    for (int i = 0; i < N; i++) {
        cin >> A[i] >> B[i] >> C[i] >> D[i]; 
    }
    int T1[N * N];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            T1[i + N * j] = A[i] + B[j];
        }
    }
    sort(T1, T1 + N * N);
    long long result = 0; int current;
    for (int i = 0; i < N * N; i++) {
        current = C[i % N] + D[i / N];
        auto probe = lower_bound(T1, T1 + N * N, -current);
        if (*probe == -current) {
            result += upper_bound(T1, T1 + N * N, -current) - probe;
        }
    } // O(N * N * log(N)) by MitM
    cout << result;
}