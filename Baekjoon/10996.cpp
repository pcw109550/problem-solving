#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);
    int N; cin >> N; if (N == 1) { cout << '*'; return 0; }
    for (int i = 0; i < N; i++) {
        for (int j = N / 2; j < N; j++) {
            cout << '*'; if (j < N - 1) { cout << ' '; }
        }
        cout << '\n';
        for (int j = 0; j < N / 2; j++) {
            cout << " *";
        }
        cout << '\n';
    }
}