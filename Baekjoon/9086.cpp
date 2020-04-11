#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int N; string s; cin >> N; getline(cin, s);
    for (int i = 0; i < N; i++) {
        getline(cin, s); cout << s[0] << s[s.length() - 1] << '\n';
    }
}