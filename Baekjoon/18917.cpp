#include<bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    long long sum = 0;
    int Xor = 0;
    int M, x, a;
    cin >> M;
    while (M--) {
        cin >> a;
        if (a == 1) {
            cin >> x;
            Xor ^= x;
            sum += x;
        } else if (a == 2) {
            cin >> x;
            Xor ^= x;
            sum -= x;
        } else if (a == 3) {
            cout << sum << '\n';
        } else {
            cout << Xor << '\n';
        }
    }
}   