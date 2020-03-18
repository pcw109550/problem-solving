#include <bits/stdc++.h>
using namespace std;

int div_n(int num, int n) {
    int result = 0;
    while (num) {
        result += num / n;
        num /= n;
    }
    return result;
}

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);
    int N, M; cin >> N >> M;
    int num5 = div_n(N, 5) - div_n(M, 5) - div_n(N - M, 5);
    int num2 = div_n(N, 2) - div_n(M, 2) - div_n(N - M, 2);
    cout << (num2 ? min(num2, num5) : 0);
}