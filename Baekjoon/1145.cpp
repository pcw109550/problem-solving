#include <bits/stdc++.h>
using namespace std;

inline int lcm(int a, int b) { return a * b / __gcd(a, b); }

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);
    int input[5] = {}, idx[3] = {}, result = (1 << 30) - 1, start = 0, lcmval;
    for (int i = 0; i < 5; i++) { cin >> input[i]; }
    for (int i = 0; i < 5; i++) {
        for (int j = i + 1; j < 5; j++) {
            start = 0;
            for (int k = 0; k < 5; k++) {
                if (k == i || k == j) { continue; }
                idx[start++] = k;
            }
            lcmval = lcm(lcm(input[idx[0]], input[idx[1]]), input[idx[2]]);
            if (result > lcmval) {
                result = lcmval;
            }
        }
    }
    cout << result;
}