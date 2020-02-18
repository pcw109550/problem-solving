#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);
    int N; cin >> N;
    for (int i = 1; i < 10; i++) {
        cout << N << " * " << i << " = " << N * i << "\n";
    }
}