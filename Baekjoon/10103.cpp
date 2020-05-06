#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int a, b, s1, s2, N; a = b = 100;
    cin >> N;
    while (N--) {
        cin >> s1 >> s2;
        if (s1 > s2)      { b -= s1; }
        else if (s1 < s2) { a -= s2; }
    }
    cout << a << '\n' << b;
}