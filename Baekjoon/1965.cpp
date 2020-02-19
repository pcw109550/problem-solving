#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);
    int N; cin >> N; int input[N] = {}, Max = -1; int D[N] = {};
    for (int i = 0; i < N; i++) { cin >> input[i]; }
    for (int i = 0; i < N; i++) {
        for (int j = i - 1; j >= 0; j--) {
            if (input[j] < input[i]) { D[i] = max(D[i], D[j]); }
        }
        D[i] += 1;
        if (Max < D[i]) { Max = D[i]; }
    }
    cout << Max;
}