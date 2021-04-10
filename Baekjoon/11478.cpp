#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    string s; cin >> s;
    int N = s.size();
    unordered_set<string> S;
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j <= N - i; j++) {
            auto k = s.substr(j, i);
            S.insert(k);
        }
    }
    cout << S.size();
}