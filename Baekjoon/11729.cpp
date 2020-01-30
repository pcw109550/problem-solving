#include <bits/stdc++.h>
using namespace std;
void hanoi(int height, int src, int dest) {
    if (height == 1) {
        cout << src << " " << dest << "\n";
    } else {
        hanoi(height - 1, src, 6 - src - dest);
        hanoi(1, src, dest);
        hanoi(height - 1, 6 - src - dest, dest);
    }
}

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);
    int N; cin >> N;
    cout << (int)(pow(2, N) - 1) << '\n';
    hanoi(N, 1, 3);
}