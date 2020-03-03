#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);
    bool D[30] = {}; int temp;
    for (int i = 0; i < 28; i++) {
        cin >> temp; D[temp - 1] = true;
    }
    for (int i = 0; i < 30; i++) {
        if (!D[i]) { cout << i + 1 << '\n'; }
    }
}