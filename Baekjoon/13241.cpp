#include<bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    long long N, M;
    cin >> N >> M;
    cout << N * M / __gcd(N, M);
}