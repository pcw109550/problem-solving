#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);
    int N, temp; cin >> N; int input[N] = {};
    for (int i = 0; i < N; i++) { cin >> input[i]; }
    int D[N] = {}; int Max = -1; int sum[N] = {};
    for (int i = 0; i < N; i++) {
        D[i] = 1; temp = -1;
        for (int j = i - 1; j >= 0; j--) {
            if (input[i] > input[j]) {
                D[i] = max(D[i], D[j] + 1);
                sum[i] = max(sum[i], sum[j] + input[i]);
            }
        }
        if (sum[i] == 0) { sum[i] = input[i]; }
        Max = max(sum[i], Max);
    }
    cout << Max;
}