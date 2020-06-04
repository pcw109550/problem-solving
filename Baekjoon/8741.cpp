#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int K; cin >> K;
    cout << string(K, '1') << string(K - 1, '0');
}