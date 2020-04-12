#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    long long N; cin >> N;
    long long result = 5 + 7 * (N - 1) + 3 * (N - 1) * (N - 2) / 2;
    cout << result % 45678;
}