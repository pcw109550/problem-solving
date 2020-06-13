#include <bits/stdc++.h>
using namespace std;

inline void task() {
    // Kadane's algorithm O(N)
    int N, temp = 0, acc, Max = -1001; cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> acc;
        if (temp + acc <= 0) {
            temp = acc;
            Max = max(Max, temp);
        } else {
            temp = max(temp + acc, acc);
            Max = max(Max, temp);
        }
         
    }
    cout << Max << '\n';
}

int main(void) {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int T; cin >> T;
    while (T--) { task(); }
}