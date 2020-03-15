#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);
    string s; cin >> s; bool start = false;
    for (int j = 2; j >= 0; j--) {
        int current = s[0] - '0';
        if (s.length() == 1 && current == 0) { cout << 0; return 0; }
        int temp = (current >> j) & 1;
        if (!start && temp == 1) { start = true; cout << 1; }
        else if (start) { cout << temp; }
    }
    char output[3 * s.length() - 1] = {};
    for (int i = 1; i < s.length(); i++) {
        for (int j = 2; j >= 0; j--) {
            output[3 * (i - 1) + 2 - j] = (((s[i] - '0') >> j) & 1) + '0';
        }
    }
    cout << output;
}