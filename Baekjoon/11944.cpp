#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int N, M; cin >> N >> M;
    string s = to_string(N);
    int len = s.length();
    if (len * N <= M) {
        for (int i = 0; i < N; i++) {
            cout << s;
        }
    } else {
        for (int i = 0; i < M / len; i++) {
            cout << s;
        }
        if (M % len != 0) {
            for (int i = 0; i < M % len; i++) {
                cout << s[i];
            }
        }
    }
}