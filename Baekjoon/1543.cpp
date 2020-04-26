#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    string s1, s2; getline(cin, s1); getline(cin, s2);
    int probe = 0, result = 0;
    while (probe < s1.length()) {
        if (!s1.compare(probe, s2.length(), s2)) {
            result++;
            probe += s2.length();
        } else {
            probe++;
        }
    }
    cout << result;
}