#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);
    string s; getline(cin, s); int N = stoi(s);
    int cnt = 0;
    for (int i = 0; i < N; i++) {
        getline(cin, s);
        for (auto it = s.begin(); it != s.end(); it++) {
            if ((*it) == '(') { cnt++; }
            else { cnt--; }
            if (cnt < 0) { break; }
        }
        if (cnt != 0) { printf("NO\n"); }
        else { printf("YES\n"); }
        cnt = 0;
    }
}