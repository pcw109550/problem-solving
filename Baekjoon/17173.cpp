#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);
    int N, M, sum = 0; cin >> N >> M;
    int input[M] = {}; for (int i = 0; i < M; i++) { cin >> input[i]; }
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j < M; j++) {
            if (i % input[j] == 0) { sum += i; break; }
        }
    }
    cout << sum;
}