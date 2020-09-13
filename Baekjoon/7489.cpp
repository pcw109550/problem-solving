#include<bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int D[1002] = {}, temp;
    D[1] = 1;
    for (int i = 2; i <= 1001; i++) {
        temp = i;
        D[i] = D[i - 1];
        while (temp % 5 == 0) {
            temp /= 5;
            D[i] /= 2;
        }
        D[i] *= temp;
        D[i] %= 10000;
    }
    int T, N;
    cin >> T;
    while (T--) {
        cin >> N;
        cout << D[N] % 10 << '\n';
    }
}   