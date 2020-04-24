#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int N, K, cnt = 0, num = 0; cin >> N >> K;
    vector<int> idx;
    for (int i = 0; i < 64; i++) {
        if (!(N & 1)) {
            idx.push_back(num);
        }
        N >>= 1;
        num++;
    }
    long long result = 0;
    while (K > 0) {
        if (K & 1) { result += ((long long)1 << idx.at(cnt)); }
        cnt++;
        K >>= 1;
    }
    cout << result;
}