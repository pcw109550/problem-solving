#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);
    int temp, out = 0;
    for (int i = 0; i < 3; i++) {
        cin >> temp; out += temp == 1;
    }
    int result = out > (3 - out) ? 1 : 2;
    cout << result;
}