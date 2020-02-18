#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);
    int N; cin >> N; int input[N] = {}, idx[N] = {};
    for (int i = 0; i < N; i++) { cin >> input[i]; idx[i] = i; }
    int cnt = 0, sum, max = -1;
    do {
        sum = 0;
        for (int i = 0; i < N - 1; i++) {
            sum += abs(input[idx[i]] - input[idx[i + 1]]);
        }
        if (max < sum) { max = sum; }
    } while (next_permutation(idx, idx + N));
    cout << max;
}