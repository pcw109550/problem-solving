#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);
    int N; cin >> N; int input[N] = {};
    for (int i = 0; i < N; i++) { cin >> input[i]; }
    int D[N] = {};
    for (int i = 0; i < N; i++) {
        if (input[i] == 0) { continue; }
        for (int j = i + 1; j <= i + input[i]; j++) {
            if (i != 0 && D[i] == 0) { break; }
            if (D[j] == 0) { D[j] = D[i] + 1; }
            else { D[j] = min(D[j], D[i] + 1); }
        }
    }
    if (N == 1) { cout << 0; }
    else { cout << (!D[N - 1] ? -1 : D[N - 1]); }
}