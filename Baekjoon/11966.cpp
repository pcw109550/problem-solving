#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);
    int N; cin >> N;
    while (N > 1) {
        if (N & 1) { cout << 0; return 0; }
        N >>= 1;
    }
    cout << 1; 
}