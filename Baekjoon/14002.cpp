#include<bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    // O(N ** 2) LIS
    int N, result = 0;
    cin >> N;
    int input[N] = {};
    vector<int> trace;
    for (int i = 0; i < N; i++)
        cin >> input[i];
    int D[N + 1] = {};
    int prev[N] = {};
    fill(prev, prev + N, -1);
    int result_idx = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j < i; j++) {
            if (input[i - 1] > input[j - 1]) {
                if (D[i] < D[j]) {
                    D[i] = D[j];
                    prev[i - 1] = j - 1;
                }
            }
        }
        D[i] += 1;
        if (result < D[i]) {
            result = D[i];
            result_idx = i - 1;
        }
    } 
    cout << result << '\n';
    int idx = result_idx;
    do {
        trace.emplace_back(input[idx]);
        idx = prev[idx];
    } while (idx != -1);
    for (auto it = trace.rbegin(); it != trace.rend(); it++)
        cout << *it << ' ';
    return 0;
}