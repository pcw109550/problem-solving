#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int N, Q, L, R;
    cin >> N >> Q;
    int input[N] = {}, acc[N + 1] = {};
    for (int i = 0; i < N; i++) { cin >> input[i]; }
    sort(input, input + N);
    for (int i = 0; i < N; i++) {
        acc[i + 1] = acc[i] + input[i];
    }
    while (Q--) {
        cin >> L >> R;
        cout << acc[R] - acc[L - 1] << '\n';
    }
}