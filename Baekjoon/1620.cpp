#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int N, T; string s; cin >> N >> T; string data[N] = {};
    map<string, int> data2;
    for (int i = 0; i < N; i++) {
        cin >> data[i]; data2.insert({data[i], i});
    }
    getline(cin, s);
    for (int i = 0; i < T; i++) {
        getline(cin, s);
        if ('0' <= s[0] && s[0] <= '9') {
            cout << data[stoi(s) - 1] << '\n';
        } else { // O(log n)
            cout << data2.find(s)->second + 1 << '\n';
        }
    }
}