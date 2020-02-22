#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);
    int N; cin >> N; int D[N][2] = {};
    D[0][0] = D[0][1] = 1; 
    for (int i = 1; i < N; i++) {
        D[i][0] = (D[i - 1][0] + 2 * D[i - 1][1]) % 9901;
        D[i][1] = (D[i - 1][0] + D[i - 1][1]) % 9901;
    }
    int result = (D[N - 1][0] + 2 * D[N - 1][1]) % 9901;
    cout << result;
}