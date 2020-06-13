#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int N; cin >> N;
    if (N == 0) { cout << "NO"; return 0; }
    while (N > 0) {
        if (N % 3 == 2) {
            cout << "NO";
            return 0;
        }
        N /= 3;
    }
    cout << "YES";
}