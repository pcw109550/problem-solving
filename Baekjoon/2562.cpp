#include <bits/stdc++.h>
using namespace std;
int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);
    int max = 0, cnt = 0, temp = 0;
    for (int i = 0; i < 9; i++) {
        cin >> temp; if (temp > max) {max = temp; cnt = i; }
    }
    cout << max << "\n" << cnt + 1;
}