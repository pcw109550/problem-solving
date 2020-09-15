#include<bits/stdc++.h>
using namespace std;

inline void task(void) {
    long long cnt = 0;
    long long N; cin >> N;
    if (N == 1) {
        cout << 1 << '\n';
        return;
    }
    bool div = false;
    for (int i = 2; i * i <= N; i++) {
        while (N % i == 0) {
            div = true;
            N /= i;
        }
        if (div) {
            div = false;
            cnt++;
        }
    }
    if (N != 1)
        cnt++;
    cout << (1 << (cnt - 1)) << '\n';
}

int main(void) {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--)
        task();
}   