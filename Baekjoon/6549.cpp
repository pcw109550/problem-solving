#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    // O(N)
    while (true) {
        long long N, Max = 0; cin >> N;
        if (N == 0)
            return 0;
        vector<long long> M(N, 0);
        for (long long i = 0; i < N; i++)
            cin >> M[i];
        stack<long long> S; S.push(-1);
        for (long long i = 0; i < N; i++) {
            while (S.top() != -1 && M[S.top()] >= M[i]) {
                long long j = S.top(); S.pop();
                Max = max(Max, M[j] * (i - S.top() - 1));
            }
            S.push(i);
        }
        while (S.top() != -1) {
            long long i = S.top(); S.pop();
            Max = max(Max, M[i] * (N - S.top() - 1));
        }
        cout << Max << '\n';
    }
}
