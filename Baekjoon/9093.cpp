#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T; string s; getline(cin, s);
    char input[1001];
    for (int t = 0; t < T; t++) {
        memset(input, 0, 1001);
        getline(cin, s); strncpy(input, s.c_str(), s.length());
        char *token = strtok(input, " ");
        while (token != NULL) {
            reverse(token, token + strlen(token));
            cout << token;
            token = strtok(NULL, " ");
            if (token != NULL) { cout << ' '; }
        }
        cout << '\n';
    }
}