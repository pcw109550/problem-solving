#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);
    int a, b, result = 1, temp; cin >> a >> b;
    for (int i = a; i <= b; i++) {
        temp = (i * (i + 1) / 2) % 14579;
        result *= temp; result %= 14579;
    }
    cout << result;
}