#include<bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int R, B, L, W;
    cin >> R >> B;
    for (int i = 1; i <= (R + 4) / 2; i++) {
        L = i;
        W = (R + 4) / 2 - L;
        if ((L - 2) * (W - 2) == B) {
            int Max = max(L, W);
            cout << Max << ' ' << L + W - Max;
            return 0;
        }
    }
}   