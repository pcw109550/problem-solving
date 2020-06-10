#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false); cin.tie(NULL);
    long long N, result = 0, weight = 1; cin >> N;
    while (N > 0) {
        result += (N & 1) * weight;
        N >>= 1;
        weight *= 3;
    }
    cout << result;
}