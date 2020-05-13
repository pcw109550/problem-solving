#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int N; cin >> N; string s;
    while (N--) {
        cin >> s; cout << ((s[s.length() - 1] - '0') % 2 ? "odd\n" : "even\n");
    }
}