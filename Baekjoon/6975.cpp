#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);
    int T, N, sum; cin >> T;
    string current, s[3] = {" deficient", " perfect", "n abundant"};
    for (int t = 0; t < T; t++) {
        cin >> N; sum = 0;
        for (int i = 1; i < N; i++) {
            if (N % i == 0) { sum += i; }
        }
        if (sum < N) { current = s[0]; }
        else if (sum == N) { current = s[1]; }
        else { current = s[2]; }
        cout << N << " is a" << current << " number.\n";
        if (t != T - 1) { cout << '\n'; }
    }
}