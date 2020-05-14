#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int N, M; cin >> N >> M; int D[N + 1] = {};
    int start, end;
    for (int i = 1; i <= N; i++) {
        cin >> D[i]; D[i] += D[i - 1];
    }
    for (int i = 0; i < M; i++) {
        cin >> start >> end;
        cout << D[end] - D[start - 1] << '\n';
    }
}