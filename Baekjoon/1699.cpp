#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);
    int N, Min; cin >> N; int D[N + 1] = {};
    for (int i = 1; i <= N; i++) {
        int root = floor(sqrt(i));
        if (root * root == i) { D[i] = 1; continue; }
        Min = 1 << 30;
        for (int j = 1; j <= root; j++) {
            Min = min(Min, D[i - j * j] + 1);
        }
        D[i] = Min;
    }
    cout << D[N];
}