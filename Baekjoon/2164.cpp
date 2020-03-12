#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);
    int N; cin >> N; queue<int> Q;
    for (int i = 1; i <= N; i++) { Q.push(i); }
    for (int i = 0; i < N - 1; i++) {
        Q.pop(); auto current = Q.front(); Q.pop(); Q.push(current);
    }
    cout << Q.front();
}