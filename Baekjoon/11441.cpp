#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int N, M, start, end; int acc = 0, temp; cin >> N;
    int D[N + 1] = {}; // DP
    for (int i = 1; i <= N; i++) {
        cin >> temp; acc += temp; D[i] = acc;
    }
    cin >> M; 
    for (int i = 0; i < M; i++) {
        cin >> start >> end;
        cout << D[end] - D[start - 1] << '\n';
    }
}