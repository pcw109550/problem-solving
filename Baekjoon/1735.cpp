#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int a, b, c, d; cin >> a >> b >> c >> d;
    int numerator = a * d + b * c;
    int denominator = b * d;
    int gcd = __gcd(numerator, denominator);
    cout << numerator / gcd << ' ' << denominator / gcd;
}