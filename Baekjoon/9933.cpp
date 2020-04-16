#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int N; cin >> N; string input[N] = {};
    for (int i = 0; i < N; i++) { cin >> input[i]; }
    for (int i = 0; i < N; i++) {
        string s = input[i];
        reverse(s.begin(), s.end());
        if (!s.compare(input[i])) {
            cout << s.length() << ' ' << s[s.length() / 2];
        }
        for (int j = i + 1; j < N; j++) {
            if (!s.compare(input[j])) {
                cout << s.length() << ' ' << s[s.length() / 2];
            }
        }
    }
}