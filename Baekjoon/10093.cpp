#include <bits/stdc++.h>
using namespace std;
int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);
    unsigned long long a, b, temp; cin >> a >> b;
    if (a == b) { cout << 0; return 0; }
    if (a > b) { temp = a; a = b; b = temp; }
    cout << b - a - 1<< "\n";
    for(unsigned long long i = a + 1; i < b; i++) {
        cout << i;
        if (i != b - 1) { cout << " "; }
    }
}