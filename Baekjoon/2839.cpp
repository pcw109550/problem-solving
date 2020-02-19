#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);
    int N; cin >> N; int sum = 10000, x, y;
    // O(1) solution exists but lazy me!
    if (N == 4 || N == 7) { sum = -1; }
    for (int i = 0; i <= N; i += 5) {
        if ((N - i) % 3 == 0) {
            x = i / 5; y = (N - i) / 3;
            if ((x + y) < sum) { sum = x + y; }
        }
    }
    cout << sum;
}