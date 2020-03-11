#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);
    int N, r, e, c; cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> r >> e >> c;
        int temp = e - c;
        if (temp > r) { cout << "advertise\n"; }
        else if (temp < r) { cout << "do not advertise\n"; }
        else { cout << "does not matter\n"; }
    }
}