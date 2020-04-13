#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; string s1, s2, s3; bool check; cin >> T; getline(cin, s1);
    for (int i = 0; i < T; i++) {
        getline(cin, s1);
        int temp = 0;
        temp += stoi(s1);
        reverse(s1.begin(), s1.end());
        temp += stoi(s1);
        s2 = to_string(temp);
        for (int j = 0; j < s2.length() / 2 + 1; j++) {
            check = true;
            if (s2[j] != s2[s2.length() - j - 1]) {
                cout << "NO\n"; check = false; break;
            }
        }
        if (check) { cout << "YES\n"; }
    }
}