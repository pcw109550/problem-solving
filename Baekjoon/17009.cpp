#include<bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int A, B, x, y, z;
    cin >> x >> y >> z;
    A = 3 * x + 2 * y + z;
    cin >> x >> y >> z;
    B = 3 * x + 2 * y + z;
    if (A > B)      { cout << 'A'; }
    else if (A < B) { cout << 'B'; }
    else            { cout << 'T'; }
}