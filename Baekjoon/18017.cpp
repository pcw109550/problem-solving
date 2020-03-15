#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);
    long double a, b; cin >> a >> b; long double c = 299792458.0;
    cout.precision(19);
    cout << (a + b) / (1 + a * b / (c * c));
}