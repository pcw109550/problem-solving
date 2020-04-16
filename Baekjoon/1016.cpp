#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    long long Min, Max; cin >> Min >> Max;
    int cnt = Max - Min + 1; int prime[78498] = {}; int primecnt = 0;
    int maxsquare = (int)sqrt(Max);
    vector<bool> temp(maxsquare + 1, false);
    for(int i = 2; i <= maxsquare; i++) {
        if (temp[i]) { continue; }
        prime[primecnt++] = i;
        for(int j = i; j <= maxsquare; j += i) {
            temp[j] = true;
        }
    }
    vector<bool> check(Max - Min + 1, true);
    for (int i = 0; i < primecnt; i++) {
        long long square = (long long)prime[i] * prime[i];
        long long idx = Min + (Min % square == 0 ? 0 : (square - Min % square));
        while (idx <= Max) {
            if (check[idx - Min]) { check[idx - Min] = false; cnt--; }
            idx += square;
        }
    }
    cout << cnt;
}