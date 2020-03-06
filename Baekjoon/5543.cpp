#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);
    int B[3], D[2]; int Min = 1 << 30;
    for (int i = 0; i < 3; i++) { cin >> B[i]; }
    for (int i = 0; i < 2; i++) { cin >> D[i]; }
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 2; j++) {
            Min = min(Min, B[i] + D[j]);
        }
    }
    cout << Min - 50;
}