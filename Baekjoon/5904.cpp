#include<bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int N, idx = 0;
    cin >> N;
    int D[29] = {};
    D[0] = 3;
    for (int i = 1; i < 29; i++) {
        D[i] = 2 * D[i - 1] + i + 3;
        if (N > D[i])
            idx = i;
        else
            break;
    }
    while (true) {
        if (idx < 0) {
            cout << (N == 1 ? 'm' : 'o');
            break;
        }
        if (D[idx] < N && N <= D[idx] + idx + 4) {
            cout << (N - D[idx] == 1 ? 'm' : 'o');
            break;
        }
        N = (D[idx] + idx + 4 < N ? N - D[idx] - idx - 4 : N);
        idx--;
    }
}   