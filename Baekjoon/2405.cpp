#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int N; cin >> N; int input[N] = {};
    for (int i = 0; i < N; i++) { cin >> input[i]; }
    sort(input, input + N);
    int Max = -(1 << 30), Min = 1 << 30;
    for (int i = 1; i < N - 1; i++) {
        Max = max(Max, 3 * input[i] - input[i] - input[i + 1] - input[0]);
        Min = min(Min, 3 * input[i] - input[i] - input[i - 1] - input[N - 1]);
    }
    cout << max(abs(Max), abs(Min));
}