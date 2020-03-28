#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);
    long long A, B; cin >> A >> B;
    if (A > B) swap(A, B);
    __int128_t result = 0;
    result += (__int128_t) (B - A + 1) * A;
    result += (__int128_t) (B - A) * (B - A + 1) / 2;
    cout << (long long)result;
}