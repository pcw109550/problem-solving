#include <bits/stdc++.h>
using namespace std;

inline int phi(int N) {
    if (N == 1) { return 0; }
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
    int N;
    while (true) {
        cin >> N; if (!N) { return 0; }
        cout << phi(N) << '\n';
    }
}