#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int x, arr[6] = {1, 1, 2, 2, 2, 8};
    for (int i = 0; i < 6; i++) {
        cin >> x; cout << arr[i] - x << ' ';
    }
}