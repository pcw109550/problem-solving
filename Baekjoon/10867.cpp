#include <bits/stdc++.h>
using namespace std;
int cnt[2001];

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);
    int N, temp; cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> temp; cnt[temp + 1000]++;
    }
    for (int i = 0; i <= 2000; i++) {
        if( cnt[i]) { cout << i - 1000 << ' '; }
    }
}