#include <bits/stdc++.h>
using namespace std;
#define FIELD 1000000009

int main(void) {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int N, T; cin >> T;
    int D[1000000] = {1, 2, 4, };
    for (int i = 3; i < 1000000; i++) {
        D[i] = ((D[i - 1] + D[i - 2]) % FIELD + D[i - 3]) % FIELD;
    }
    while (T--) {
        cin >> N;
        cout << D[N - 1] << '\n';
    }
}