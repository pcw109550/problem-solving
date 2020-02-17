#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);
    int T, cnt; long long sum; cin >> T;
    for (int t = 0; t < T; t++) {
        cin >> cnt; int input[cnt] = {}; sum = 0;
        for (int i = 0; i < cnt; i++) { cin >> input[i]; }
        for (int i = 0; i < cnt; i++) {
            for (int j = i + 1; j < cnt; j++) {
                sum += __gcd(input[i], input[j]);
            }
        }
        cout << sum << '\n';
    }
}