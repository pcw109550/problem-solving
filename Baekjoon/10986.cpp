#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int N, M; int acc = 0, temp; cin >> N >> M;
    int D[N + 1] = {}; int occur[M] = {}; // DP
    for (int i = 1; i <= N; i++) {
        cin >> temp;
        acc += temp;
        acc %= M;
        D[i] = acc;
        occur[acc]++;
    }
    long long result = occur[0];
    for (int i = 0; i < M; i++) {
        if (occur[i] > 1) {
            result += (long long)occur[i] * (occur[i] - 1) / 2;
        }
    }
    cout << result;
}