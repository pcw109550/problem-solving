#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);
    int N, result = 0; cin >> N; int input[N] = {};
    for (int i = 0; i < N; i++) { cin >> input[i]; }
    int D[N] = {};
    for (int i = 0; i < N; i++) {
        for (int j = i; j >= 0; j--) {
            if (input[i] > input[j]) {
                D[i] = max(D[i], D[j]);
            }
        }
        D[i]++;
        result = max(D[i], result);
    }
    cout << N - result;
}