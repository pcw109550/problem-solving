#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int N; cin >> N;
    if (N < 100) { cout << N % 10 + N / 10; }
    else if (N < 1010) {
        if (N % 10 == 0) { cout << N % 100 + N / 100; }
        else { cout << N % 10 + N / 10; }
    } else { cout << 20; }
}