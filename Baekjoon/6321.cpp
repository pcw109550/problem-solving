#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int N; cin >> N;
    string s;
    for (int i = 1; i <= N; i++) {
        cin >> s;
        cout << "String #" << i << '\n';
        for (int j = 0; j < s.length(); j++)
            s[j] = (s[j] - 'A' + 1) % 26 + 'A';
        cout << s << '\n';
        if (i != N)
            cout << '\n';
    }
}