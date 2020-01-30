#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);
    string s; getline(cin, s);
    int cnt = 0, result = 0, temp = 0;
    for (auto it = s.begin(); it != s.end(); it++ ) {
        if ((*it) == '(') {
            temp = 1;
            cnt++;
        } else {
            cnt--;
            if (temp == 1) {
                result += cnt;
            } else {
                result += 1;
            }
            temp = 0;
        }
    }
    cout << result;
}