#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    // O(N)
    int N, Max = 0; cin >> N;
    vector<int> M(N, 0);
    for (int i = 0; i < N; i++)
        cin >> M[i];
    stack<int> S; S.push(-1);
    for (int i = 0; i < N; i++) {
        while (S.top() != -1 && M[S.top()] >= M[i]) {
            int j = S.top(); S.pop();
            Max = max(Max, M[j] * (i - S.top() - 1));
        }
        S.push(i);
    }
    while (S.top() != -1) {
        int i = S.top(); S.pop();
        Max = max(Max, M[i] * (N - S.top() - 1));
    }
    cout << Max;
}