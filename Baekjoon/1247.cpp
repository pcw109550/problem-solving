#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);
    int N; long long temp; __int128_t S;
    for (int t = 0; t < 3; t++) {
        cin >> N; S = 0;
        for (int i = 0; i < N; i++) { cin >> temp; S += temp; }
        if (S > 0) { cout << "+\n"; }
        else if (S < 0) { cout << "-\n"; }
        else { cout << "0\n"; }
    }
}