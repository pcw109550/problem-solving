#include <bits/stdc++.h>
using namespace std;

inline int form(int A) {
    int d1 = A % 10;
    int d2 = (A % 100 - d1) / 10;
    int d3 = (A / 100);
    return 100 * d1 + 10 * d2 + d3;
}

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);
    int A, B; cin >> A >> B;
    A = form(A); B = form(B);
    if (A > B) { cout << A; } else { cout << B; }
}