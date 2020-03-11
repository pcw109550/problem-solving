#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);
    int N, M;
    while (true) {
    cin >> N >> M;
        if (M == 0 && N == 0) { break; }
        if (M % N == 0) { cout << "factor\n"; }
        else if (N % M == 0) { cout << "multiple\n"; }
        else { cout << "neither\n"; }
    }
}