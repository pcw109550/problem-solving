#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int N, M, x, y; cin >> N >> M; int temp[N + 1] = {};    
    for (int i = 1; i <= N; i++) { temp[i] = i; }
    for (int i = 0; i < M; i++) {
        cin >> x >> y;
        reverse(temp + x, temp + y + 1);
    }
    for (int i = 1; i <= N; i++) {
        cout << temp[i] << ' ';
    }
}