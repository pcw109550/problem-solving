#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int D, K; cin >> D >> K;
    int x = 1, y = 1;
    for (int i = 0; i < D - 3; i++) {
        int temp = x + y;
        x = y;
        y = temp;
    }
    for (int i = 1; x * i <= K; i++) {
        if ((K - x * i) % y == 0) {
            cout << i << '\n' << (K - x * i) / y;
            return 0;
        }
    }
}