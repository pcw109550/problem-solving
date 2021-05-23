#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int N; cin >> N;
    int L = 1 << N;
    vector<int> A (L);
    for (int i = 0; i < L; i++)
        cin >> A[i];
    for (int i = 0; i < L; i++)
        for (int j = 1; j < L; j++) {
            if (A[i] + A[j] < A[i & j] + A[i | j]) {
                cout << i << ' ' << j;
                return 0;
            }
        }
    cout << -1;
}