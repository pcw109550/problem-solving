#include<bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int A, B;
    cin >> A >> B;
    int gcd = __gcd(B - A, B);
    cout << (B - A) / gcd << ' ' << B / gcd;
}   