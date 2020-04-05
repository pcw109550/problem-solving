#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    long long A, B, C, D; cin >> A >> B >> C >> D;
    long long result = B + D;
    while (B > 0) { A *= 10; B /= 10; }
    while (D > 0) { C *= 10; D /= 10; }
    cout << result + A + C;
}