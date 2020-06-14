#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false); cin.tie(NULL);
    string s; cin >> s;
    int start = s.length() % 3;
    int temp = 0;
    for (int i = 0; i < start; i++) {
        temp += (1 << i) * (s[start - i - 1] - '0');
    }
    if (start != 0) {
        cout << temp;
    }
    for (int i = start; i < s.length(); i += 3) {
        temp = 0;
        for (int j = 2; j >= 0; j--) {
            temp += (1 << j) * (s[i + 2 - j] - '0');
        }
        cout << temp;
    }
}