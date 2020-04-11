#include <bits/stdc++.h>
using namespace std;

/* http://publications.waset.org/9996770/pdf */

inline int phi(int N) {
    if (N == 1) { return 1; }
    int result = 1;
    for (int i = 2; i * i <= N; i++) {
        while (N % i == 0) {
            N /= i;
            if (N % i == 0) { result *= i; }
            else { result *= i - 1; }
        }

    }
    if (N != 1) { result *= N - 1; }
    return result;
}

int main(void) {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T, N, x, result; cin >> T;
    while (T--) {
        result = 1; cin >> N;
        while (N--) {
            cin >> x;
            result = ((long long)result * phi(x)) % 1000000007;
        }
        cout << result << '\n';
    }
}