#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int a, b; cin >> a >> b;
    int gcd = __gcd(a, b);
    int A = a / gcd, B = b / gcd;
    cout << (long long)gcd * (A + B - 1);
}