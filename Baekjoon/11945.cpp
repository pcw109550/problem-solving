#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int N, M; cin >> N >> M; char s[M + 1] = {};
    while (N--) {
        cin >> s;
        for (int i = M - 1; i >= 0; i--) {
            cout << s[i];
        }
        cout << '\n';
    }
}