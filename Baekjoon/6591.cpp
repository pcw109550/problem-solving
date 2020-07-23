#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int N, K;
    while (true) {
        cin >> N >> K;
        if (N == 0 && K == 0)
            return 0;
        K = min(K, N - K);
        long long result = 1;
        for (int i = 1; i <= K; i++)
            result = result * (N - i + 1) / i;
        cout << result << '\n';
    }
}