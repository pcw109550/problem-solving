#include<bits/stdc++.h>
using namespace std;

inline void printResult(int trial, long long a, long long b) {
    cout << '#' << trial << ' ';
    cout << a << ' ' << b << '\n';
}

int main(void) {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T;
    long long D[93] = {};
    D[1] = 1;
    for (int i = 2; i <= 92; i++) {
        D[i] = D[i - 1] + D[i - 2];
    }
    cin >> T;
    for (int t = 1; t <= T; t++) {
        int N; cin >> N;
        printResult(t, D[N + 2], D[N + 1]);
    }
}