#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);
    int N; cin >> N; int a = 1, b = 0, temp;
    while (N--) {
        temp = (a + b) % 1000000007;
        a = b;
        b = temp;
    }
    cout << b;
}