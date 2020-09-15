#include<bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int a, b, c, shift; string s;
    while (true) {
        cin >> a >> b >> c;
        if (a == 0 && b == 0 && c == 0)
            return 0;
        cin.ignore();
        getline(cin, s);
        shift = (a + b + c) % 25;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] > 'z' || s[i] < 'a')
                continue;
            s[i] = 'a' + (s[i] - 'a' + 25 - shift) % 26;
        }
        cout << s << '\n';
    }
}   