#include<bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int a, b, c, d, e, f;
    cin >> a >> b >> c >> d >> e >> f;
    int D = a * e - b * d;
    int x = (e * c - b * f) / D;
    int y = (a * f - c * d) / D;
    cout << x << ' ' << y;
}   