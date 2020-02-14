#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);
    int T, max = 0; cin >> T; int input[T] = {};
    for (int i = 0; i < T; i++) {
        cin >> input[i]; if (max < input[i]) { max = input[i]; }
    }
    long long D[max] = {}; D[0] = D[1] = D[2] = 1; D[3] = D[4] = 2;
    for (int i = 5; i < max; i++) {
        D[i] = D[i - 1] + D[i - 5];
    }
    for (int i = 0; i < T; i++) {
        cout << D[input[i] - 1] << '\n';
    }
}