#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);
    int N; cin >> N; int input[N] = {};
    for (int i = 0; i < N; i++) { cin >> input[i]; }
    stack<pair<int, int>> S;
    long long result = 0;
    for (int i = N - 1; i >= 0; i--) {
        int cnt = -1;
        while (!S.empty()) {
            auto current = S.top();
            if (current.first < input[i]) { S.pop(); }
            else { break; }
        }
        if (S.empty()) { cnt = -1; }
        else { cnt = S.top().second; }
        result += N - 2 - i - cnt;
        S.push({input[i], N - 1 - i});
    }
    cout << result;
}