#include <bits/stdc++.h>
using namespace std;
int cnt[10001];

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);
    int N, temp; cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> temp; cnt[temp]++;
    }
    for (int i = 1; i <= 10000; i++) {
        for (int j = 0; j < cnt[i]; j++) {
            cout << i << '\n';
        }
    }
}