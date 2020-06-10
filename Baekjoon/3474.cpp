#include <bits/stdc++.h>
using namespace std;

inline void task() {
    int N; cin >> N;
    int cnt = 0;
    for (int i = 5; i <= N; i *= 5) {
        cnt += N / i;
    }
    cout << cnt << '\n';
}

int main(void) {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int T; cin >> T;
    while (T--) { task(); }
}