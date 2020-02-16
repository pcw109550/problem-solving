#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);
    int N; cin >> N; int D[N + 1] = {}; D[2] = 3;
    if (N < 4) { cout << D[N]; return 0; }
    for (int i = 4; i <= N; i += 2) {
        D[i] = 3 * D[i - 2] + 2;
        for (int j = i - 4; j >= 2; j -= 2)
        D[i] += 2 * D[j]; 
    }
    cout << D[N];
}