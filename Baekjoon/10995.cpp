#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int N; cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 2 * N - 1; j++) {
            if (!((i % 2 + j) % 2)) { cout << '*'; }
            else                    { cout << ' '; }
        }
        if (i % 2) { cout << '*'; }
        cout << '\n';
    }
}