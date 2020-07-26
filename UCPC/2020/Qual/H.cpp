#include<bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int N; cin >> N;
    int target[N];
    int cnt = 0, total = 0;
    for (int i = 0; i < N; i++) {
        cin >> target[i];
        total += target[i];
        cnt += target[i] / 2;
    }
    if (total % 3 != 0) {
        cout << "NO";
        return 0;
    }
    cout << (total / 3 <= cnt ? "YES" : "NO");
}   